// CS200 - Final Project - Nolan Clark - 25JUL24

#include <vector>

#include "console/console.h"
#include "input_error/input_error.h"
#include "todo/todo.h"

int main()
{
  // Create a container for our Todo items
  std::vector<Todo> todos;
  // Start up our I/O
  Console console;
  console.output_help();
  // Keep running the program until the user doesn't want to anymore
  bool user_wants_to_quit = false;
  while (!user_wants_to_quit)
  {
    if (console.is_blank())
    {
      for (auto &&current_todo : todos)
      {
        console.output_todo(current_todo);
      }
      if (todos.size() > 0)
      {
        console.output_blank_line();
      }
    }
    Command user_desire = console.get_user_desire();
    switch (user_desire)
    {
    case Command::quit:
      user_wants_to_quit = true;
      break;
    case Command::create:
      try
      {
        Todo todo = console.get_new_todo();
        todos.push_back(todo);
        console.refresh();
      }
      catch (InputError err)
      {
        console.output_error(err.describe());
      }
      break;
    case Command::toggle:
      try
      {
        unsigned int todo_num = console.get_todo_to_toggle();
        if (todo_num < 0 || todo_num >= todos.size())
        {
          throw InputError("#");
        }
        todos[todo_num].toggle_completion();
        console.refresh();
      }
      catch (InputError err)
      {
        console.output_error(err.describe());
      }
      break;
    case Command::unknown:
      break;
    }
  }
  return 0;
}
