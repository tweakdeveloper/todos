// CS200 - Final Project - Nolan Clark - 25JUL24

#pragma once

#include <string>

#include "../todo/todo.h"

class Console
{
private:
  /// Returns an std::string representing the completion status of a boolean
  /// value.
  /// @param completed Whether or not the task has been marked completed.
  /// @returns "Complete" if passed `true`, and "Not Yet Complete" if passed
  /// `false`.
  std::string bool_to_completion_status_string(bool completed);

public:
  /// Prints a formatted Todo to `stdout`.
  /// @param todo The Todo to output.
  void output_todo(Todo todo);
};
