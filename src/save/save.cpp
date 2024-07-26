// CS200 - Final Project - Nolan Clark - 25JUL24

#include <algorithm>
#include <fstream>
#include <vector>

#include "../todo/todo.h"

#include "save.h"

// CONSTANTS

const char *Save::DELIMINATOR = "\u00a4";

// STATIC FUNCTIONS

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
