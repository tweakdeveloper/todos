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

Todo::Todo(std::string title, int priority, bool completed) : completed(completed),
                                                              priority(priority),
                                                              title(title)
{
}

// OPERATORS

bool operator<(const Todo &lhs, const Todo &rhs)
{
  // First tiebreaker is priority. For different priorities, the lower priority
  // should go first (lower priority numbers have higher importance).
  if (lhs.priority != rhs.priority)
  {
    return lhs.priority < rhs.priority;
  }
  // Next tiebreaker is completion status. Completed tasks go after incomplete
  // tasks.
  if (lhs.completed != rhs.completed)
  {
    return !lhs.completed;
  }
  // If all tiebreakers are equal, return false to maintain ordering.
  return false;
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
