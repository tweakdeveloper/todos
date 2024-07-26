// CS200 - Final Project - Nolan Clark - 25JUL24

#pragma once

#include <vector>

#include "../todo/todo.h"

/// A class to manage interaction with the filesystem to persist the Todos.
class Save
{
private:
  // CONSTANTS

  static const char COMPLETED_N = 'N';
  static const char COMPLETED_Y = 'Y';
  static const char DELIMINATOR = '|';

  // STATIC FUNCTIONS

  /// Convert the boolean completion status to a char representing this state
  /// to be written to the save file.
  /// @param completed The boolean representing the completion status
  /// @returns A char to represent the completion status in the file.
  static char serialize_completed(bool completed);
  /// Parse a Todo from a line in the save file.
  /// @param line The content of the line.
  /// @throws int The field that caused the error.
  /// @returns The Todo deserialized from the file.
  static Todo todo_from_line(std::string line);

public:
  // STATIC FUNCTIONS

  /// Attempt to read the Todos from the disk.
  /// @details This will insert the Todos into the container as-read from the
  /// disk. This means that if you want them sorted, you'll need to do that
  /// yourself after this function returns.
  /// @param todos The in-memory storage to read the Todos into.
  static void attempt_load(std::vector<Todo> *todos);
  /// Write the in-memory Todos to disk.
  /// @param todos The in-memory Todos to be written.
  /// @returns Whether the file write was successful or not.
  static bool write(std::vector<Todo> todos);
};
