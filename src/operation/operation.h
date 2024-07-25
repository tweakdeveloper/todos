// CS200 - Final Project - Nolan Clark - 25JUL24

#pragma once

/// This class represents the operation that the user wants to perform on a
/// Todo.
enum class Operation
{
  /// This variant represents that the user wants to delete a Todo.
  remove,
  /// This variant represents that the user wants to toggle completion of a
  /// Todo.
  toggle,
};
