// CS200 - Final Project - Nolan Clark - 25JUL24

#include <iostream>
#include <string>

#include "../command/command.h"
#include "../input_error/input_error.h"
#include "../todo/todo.h"

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

Todo Console::get_new_todo()
{
  // Escape codes to set a green foreground (32m) and reset to default (0m).
  std::cout << "\x1b[32m"
            << "+title?"
            << PROMPT
            << "\x1b[0m"
            << " "
            << std::flush;
  // We've output a line so we need to increment our number of lines to be
  // discarded.
  lines_to_discard++;
  // Get the desired title of the Todo
  std::string title;
  std::getline(std::cin, title);
  if (title.empty())
  {
    good_input = false;
    throw InputError();
  }
  // Escape codes to set a green foreground (32m) and reset to default (0m).
  std::cout << "\x1b[32m"
            << "+priority ("
            << PLATFORM_ENTER
            << " for default)?"
            << PROMPT
            << "\x1b[0m"
            << " "
            << std::flush;
  // We've output a line so we need to increment our number of lines to be
  // discarded.
  lines_to_discard++;
  // Get the desired priority of the Todo
  std::string priority_input;
  std::getline(std::cin, priority_input);
  if (priority_input.empty())
  {
    return Todo(title);
  }
  try
  {
    int priority = std::stoi(priority_input);
    return Todo(title, priority);
  }
  catch (std::out_of_range err)
  {
    throw InputError(priority_input);
  }
  catch (std::invalid_argument err)
  {
    throw InputError(priority_input);
  }
}

int Console::get_todo_to_toggle()
{
  // Escape codes to set a green foreground (32m) and reset font to default
  // (0m).
  std::cout << "\x1b[32m"
            << "/#?"
            << PROMPT
            << "\x1b[0m"
            << " "
            << std::flush;
  // We've output a line so we need to increment our number of lines to be
  // discarded.
  lines_to_discard++;
  // Read the input from the user
  std::string todo_input;
  std::getline(std::cin, todo_input);
  if (todo_input.empty())
  {
    throw InputError();
  }
  try
  {
    int todo_index = std::stoi(todo_input);
    return todo_index;
  }
  catch (std::out_of_range err)
  {
    throw InputError(todo_input);
  }
  catch (std::invalid_argument err)
  {
    throw InputError(todo_input);
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
  // We've output a line so we need to increment our number of lines to be
  // discarded.
  lines_to_discard++;
  // We want exactly one character from the user, so we'll take that and dump
  // the rest.
  char user_input;
  std::cin >> user_input;
  std::cin.ignore();
  // Reset the valid input flag for the next prompt cycle
  good_input = true;
  switch (user_input)
  {
  case 'Q':
  case 'q':
    return Command::quit;
  case '+':
    return Command::create;
  case '/':
    return Command::toggle;
  default:
    good_input = false;
    // Escape code to scroll down (T). This essentially erases our last (bad)
    // input.
    std::cout << "\x1b[T" << std::flush;
    return Command::unknown;
  }
}

bool Console::is_blank()
{
  return lines_to_discard == 0;
}

void Console::output_blank_line()
{
  std::cout << std::endl;
  // We've output a line so we need to increment our number of lines to be
  // discarded.
  lines_to_discard++;
}

void Console::output_error(std::string err)
{
  // Escape code to set a red font (31m) and reset to default (0m).
  std::cout << "\x1b[31m"
            << err
            << "\x1b[0m"
            << std::endl;
  // We've output a line so we need to increment our number of lines to be
  // discarded.
  lines_to_discard++;
}

void Console::output_help()
{
  // Escape codes to set a bold font (1m) and reset the font to default (0m).
  std::cout << "You can input any of the following characters:\n"
            << "\x1b[1m"
            << "+"
            << "\x1b[0m"
            << " Add a new todo"
            << " \x7c "
            << "\x1b[1m"
            << "/"
            << "\x1b[0m"
            << " Toggle completion"
            << " \x7c "
            << "\x1b[1m"
            << "q"
            << "\x1b[0m"
            << " Quit\n"
            << "Press "
            << "\x1b[1m"
            << PLATFORM_ENTER
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
  // We've output a line so we need to increment our number of lines to be
  // discarded.
  lines_to_discard++;
}

void Console::refresh()
{
  // Escape code to clear the line (2K) and scroll down (T), discarding the
  // number of lines indicated by lines_to_discard.
  for (; lines_to_discard > 0; lines_to_discard--)
  {
    std::cout << "\x1b[2K" << "\x1b[T";
  }
  std::cout << std::flush;
}
