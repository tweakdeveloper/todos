// CS200 - Final Project - Nolan Clark - 25JUL24

#include <string>

#include "todo.h"

// CONSTRUCTORS

Todo::Todo() : completed(false), priority(1), title("sample task")
{
}

Todo::Todo(std::string title) : completed(false), priority(1), title(title)
{
}

Todo::Todo(std::string title, int priority) : completed(false),
                                              priority(priority),
                                              title(title)
{
}

// GETTERS AND SETTERS

int Todo::get_priority()
{
  return priority;
}

std::string Todo::get_title()
{
  return title;
}

bool Todo::has_been_completed()
{
  return completed;
}

void Todo::set_completed(bool completed)
{
  this->completed = completed;
}

void Todo::set_priority(int priority)
{
  this->priority = priority;
}

void Todo::set_title(std::string title)
{
  this->title = title;
}

void Todo::toggle_completion()
{
  completed = !completed;
}
