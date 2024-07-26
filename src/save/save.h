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
  static const char *DELIMINATOR;

  // STATIC FUNCTIONS

  /// Convert the boolean completion status to a char representing this state
  /// to be written to the save file.
  /// @param completed The boolean representing the completion status
  /// @returns A char to represent the completion status in the file.
  static char serialize_completed(bool completed);

public:
  // STATIC FUNCTIONS

  /// Write the in-memory Todos to disk.
  /// @param todos The in-memory Todos to be written.
  /// @returns Whether the file write was successful or not.
  static bool write(std::vector<Todo> todos);
};
