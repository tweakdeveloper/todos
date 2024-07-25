// CS200 - Final Project - Nolan Clark - 25JUL24

#pragma once

#include <string>

class Todo
{
private:
  bool completed;
  int priority;
  std::string title;

public:
  // CONSTRUCTORS
  Todo();
  Todo(std::string title);
  Todo(std::string title, int priority);
  // GETTERS AND SETTERS
  int get_priority();
  std::string get_title();
  bool has_been_completed();
  void set_completed(bool completed);
  void set_priority(int priority);
  void set_title(std::string title);
};
