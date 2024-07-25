// CS200 - Final Project - Nolan Clark - 25JUL24

#pragma once

#include <string>

#include "../command/command.h"
#include "../todo/todo.h"

/// A simple class for I/O interactions, tailored to the needs of this
/// application.
/// @details This class makes heavy use of
/// [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code).
class Console
{
private:
  // CONSTANTS

  const char *PROMPT = "\xe2\x96\xb6";

  // STATE

  bool good_input = true;

  // INSTANCE METHODS

  /// Returns an std::string representing the completion status of a boolean
  /// value.
  /// @param completed Whether or not the task has been marked completed.
  /// @returns "Complete" if passed `true`, and "Not Yet Complete" if passed
  /// `false`.
  std::string bool_to_completion_status_string(bool completed);

public:
  // CONSTRUCTOR AND DESTRUCTOR

  /// The default constructor for the Console class.
  /// @details This constructor will print a welcome message to the console
  /// when it runs.
  Console();

  // INSTANCE METHODS

  /// Waits for the user to input what they want to do.
  /// @returns A Command variant reflecting the user's choice.
  Command get_user_desire();
  /// Prints a helpful message letting the user know how to interact with the
  /// program.
  void output_help();
  /// Prints a formatted Todo to `stdout`.
  /// @param todo The Todo to output.
  void output_todo(Todo todo);
};
