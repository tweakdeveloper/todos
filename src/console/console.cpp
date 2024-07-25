// CS200 - Final Project - Nolan Clark - 25JUL24

#include <iostream>

#include "console.h"

// INSTANCE METHODS

std::string Console::bool_to_completion_status_string(bool completed)
{
  if (completed)
  {
    return "Complete";
  }
  else
  {
    return "Not Yet Complete";
  }
}

void Console::output_todo(Todo todo)
{
  std::cout << todo.get_title() << " - "
            << todo.get_priority() << " - "
            << bool_to_completion_status_string(todo.has_been_completed())
            << std::endl;
}
