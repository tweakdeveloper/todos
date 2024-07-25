// CS200 - Final Project - Nolan Clark - 25JUL24

#pragma once

#include <string>

/// A simple container class representing a task to be completed.
class Todo
{
private:
  bool completed;
  int priority;
  std::string title;

public:
  // CONSTRUCTORS

  /// Default constructor for the Todo class.
  Todo();
  /// Constructor for the Todo class that sets only the title.
  Todo(std::string title);
  /// Constructor for the Todo class that sets the title and a priority.
  Todo(std::string title, int priority);

  // GETTERS AND SETTERS

  /// Get the priority of the Todo.
  /// @returns The priority of the Todo.
  int get_priority();
  /// Get the title of the Todo.
  /// @returns The title of the Todo.
  std::string get_title();
  /// Get the completion status of the Todo.
  /// @returns Whether the Todo has been marked completed or not.
  bool has_been_completed();
  /// Marks the Todo either completed or not yet completed.
  /// @param completed This should be `true` if the Todo has been completed and
  /// `false` if not.
  void set_completed(bool completed);
  /// Sets the priority of the Todo.
  /// @param priority The priority level of the Todo.
  void set_priority(int priority);
  /// Sets the title of the Todo.
  /// @param title The title of the Todo.
  void set_title(std::string title);
  /// Sets the completion status of the Todo to the opposite of its current
  /// status.
  void toggle_completion();
};
