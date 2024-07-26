// CS200 - Final Project - Nolan Clark - 25JUL24

#pragma once

/// This class represents a choice that the user made concerning what they want
/// the program to do.
enum class Command
{
  /// This variant represents that the user wants to create a new Todo.
  create,
  /// This variant represents that the user wants to quit the program.
  quit,
  /// This variant represents that the user would like to remove a Todo.
  remove,
  /// This variant represents that the user would like to toggle the completion
  /// status of a Todo.
  toggle,
  /// This variant represents that the user didn't choose from one of the valid
  /// options.
  unknown,
  /// This variant represents that the user wants to save the Todos.
  write,
};
