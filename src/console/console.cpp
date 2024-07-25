// CS200 - Final Project - Nolan Clark - 25JUL24

#include <iostream>

#include "../command/command.h"

#include "console.h"

// CONSTRUCTORS AND DESTRUCTOR

Console::Console()
{
  // Escape codes to set a bold font (1m) and reset the font to default (0m)
  std::cout << "Welcome to "
            << "\x1b[1m"
            << "todos"
            << "\x1b[0m"
            << "!\n"
            << std::endl;
}

// INSTANCE METHODS

std::string Console::bool_to_completion_status_string(bool completed)
{
  if (completed)
  {
    return "Complete";
  }
  else
  {
    return "Not Yet Complete";
  }
}

Command Console::get_user_desire()
{
  // Escape codes to set a green foreground (32m) on previously understood
  // command or a red foreground (31m) on an unknown command.
  if (good_input)
  {
    std::cout << "\x1b[32m";
  }
  else
  {
    std::cout << "\x1b[31m";
  }
  // Escape code to reset font to default (0m) and erase the rest of the line
  // (K). This is so we clear any previous bad input from the user.
  std::cout << PROMPT
            << "\x1b[0m"
            << " "
            << "\x1b[K"
            << std::flush;
  // We want exactly one character from the user, so we'll take that and dump
  // the rest.
  char user_input;
  std::cin >> user_input;
  std::cin.ignore();
  // Save the value of good_input so we can reset it for the next prompt.
  bool input_previously_good = good_input;
  good_input = true;
  switch (user_input)
  {
  case 'Q':
  case 'q':
    return Command::quit;
  case '+':
    return Command::create;
  default:
    good_input = false;
    // Escape code to scroll down (T). This essentially erases our last (bad)
    // input.
    std::cout << "\x1b[T" << std::flush;
    return Command::unknown;
  }
}

void Console::output_help()
{
  // Escape codes to set a bold font (1m) and reset the font to default (0m).
  // We use a preprocessor directive here to tell the user which key on the
  // keyboard to press to confirm because Apple likes to be different and their
  // "Return" key is the same as everyone else's "Enter" key.
  std::cout << "You can input any of the following characters:\n"
            << "\x1b[1m"
            << "+"
            << "\x1b[0m"
            << " Add a new todo"
            << " \x7c "
            << "\x1b[1m"
            << "q"
            << "\x1b[0m"
            << " Quit\n"
            << "Press "
            << "\x1b[1m"
#ifdef __APPLE__
            << "Return"
#else
            << "Enter"
#endif
            << "\x1b[0m"
            << " to confirm your choice.\n"
            << std::endl;
}

void Console::output_todo(Todo todo)
{
  std::cout << todo.get_title() << " - "
            << todo.get_priority() << " - "
            << bool_to_completion_status_string(todo.has_been_completed())
            << std::endl;
}
