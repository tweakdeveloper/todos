// CS200 - Final Project - Nolan Clark - 25JUL24

#pragma once

#include <string>

#include "../command/command.h"
#include "../operation/operation.h"
#include "../todo/todo.h"

/// A simple class for I/O interactions, tailored to the needs of this
/// application.
/// @details This class makes heavy use of
/// [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code).
class Console
{
private:
  // CONSTANTS

  // We use a preprocessor directive here to tell the user which key on the
  // keyboard to press to confirm because Apple likes to be different and their
  // "Return" key is the same as everyone else's "Enter" key.
#ifdef __APPLE__
  const char *PLATFORM_ENTER = "Return";
#else
  const char *PLATFORM_ENTER = "Enter";
#endif
  const char *PROMPT = "\xe2\x96\xb6";

  // STATE

  bool good_input = true;
  int lines_to_discard = 0;

  // INSTANCE METHODS

  /// Get a prompt for a given Operation variant.
  /// @param operation The Operation the prompt is needed for.
  /// @returns A character representing the desired Operation that can be used
  /// to display a user-facing prompt.
  char prompt_for_operation(Operation operation);

public:
  // CONSTRUCTOR AND DESTRUCTOR

  /// The default constructor for the Console class.
  /// @details This constructor will print a welcome message to the console
  /// when it runs.
  Console();

  // INSTANCE METHODS

  /// Prompts the user to input information for a new Todo.
  /// @returns A Todo based on the user's specifications.
  /// @throws InputError This method will throw an InputError if the user
  /// aborts the creation of the new Todo, perhaps by entering invalid data.
  Todo get_new_todo();
  /// Prompts the user to select which Todo they want to modify.
  /// @param operation What the user wants to due to the Todo. The value of
  /// this will affect the prompt shown to the user.
  /// @returns The index of the Todo that should be modified.
  /// @throws InputError This method will throw an InputError if the user
  /// doesn't enter a valid response.
  unsigned int get_todo_to_modify(Operation operation);
  /// Waits for the user to input what they want to do.
  /// @returns A Command variant reflecting the user's choice.
  Command get_user_desire();
  /// Is the screen a blank slate for us?
  /// @returns Whether or not the screen has been written to since the last
  /// refresh.
  bool is_blank();
  /// Prints a blank line to the terminal.
  void output_blank_line();
  /// Prints out an error message to the terminal.
  /// @param err The error to be shown to the user.
  void output_error(std::string err);
  /// Prints a helpful message letting the user know how to interact with the
  /// program.
  void output_help();
  /// Prints a formatted Todo to `stdout`.
  /// @param todo The Todo to output.
  /// @param todo_display_num An index that the user can use to reference the
  /// Todo when modifying it.
  void output_todo(Todo todo, int todo_display_num);
  /// Display whether a save operation was successful to the user.
  /// @details This function pauses for a moment to allow the user to read the
  /// status before returning. Therefore, the screen can be cleared immediately
  /// after.
  /// @param was_successful Whether or not the write was successful.
  void output_write_status(bool was_successful);
  /// Erases everything but the welcome and the help options
  void refresh();
};
