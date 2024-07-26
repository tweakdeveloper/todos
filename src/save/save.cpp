// CS200 - Final Project - Nolan Clark - 25JUL24

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../todo/todo.h"

#include "save.h"

// STATIC FUNCTIONS

void Save::attempt_load(std::vector<Todo> *todos)
{
  std::ifstream save_file_stream("saved_todos.txt");
  if (!save_file_stream.is_open())
  {
    return;
  }
  std::string save_file_line;
  while (std::getline(save_file_stream, save_file_line))
  {
    try
    {
      todos->push_back(todo_from_line(save_file_line));
    }
    catch (...)
    {
      return;
    }
  }
  save_file_stream.close();
}

char Save::serialize_completed(bool completed)
{
  if (completed)
  {
    return COMPLETED_Y;
  }
  else
  {
    return COMPLETED_N;
  }
}

Todo Save::todo_from_line(std::string line)
{
  // Start a stream so we can parse string contents
  std::stringstream line_stream(line);
  // Process field 0, the completion status
  char serialized_completion;
  line_stream >> serialized_completion;
  bool completed;
  switch (serialized_completion)
  {
  case COMPLETED_Y:
    completed = true;
    break;
  case COMPLETED_N:
    completed = false;
    break;
  default:
    throw 0;
  }
  // Ensure validity of field 1 (deliminator)
  char next;
  line_stream >> next;
  if (next != DELIMINATOR)
  {
    throw 1;
  }
  // Process field 2, the priority.
  std::string priority_string;
  std::getline(line_stream, priority_string, DELIMINATOR);
  int priority;
  try
  {
    priority = std::stoi(priority_string);
  }
  catch (...)
  {
    throw 2;
  }
  // Remainder of line should be the title
  std::string title;
  std::getline(line_stream, title);
  return Todo(title, priority, completed);
}

bool Save::write(std::vector<Todo> todos)
{
  std::ofstream save_file_stream("saved_todos.txt");
  if (!save_file_stream.is_open())
  {
    return false;
  }
  auto write_todo_to_save_file = [&save_file_stream](Todo todo)
  {
    save_file_stream << serialize_completed(todo.has_been_completed())
                     << DELIMINATOR
                     << todo.get_priority()
                     << DELIMINATOR
                     << todo.get_title()
                     << std::endl;
  };
  std::for_each(todos.begin(), todos.end(), write_todo_to_save_file);
  save_file_stream.close();
  return true;
}
