// CS200 - Final Project - Nolan Clark - 25JUL24

#include <algorithm>
#include <vector>

#include "console/console.h"
#include "input_error/input_error.h"
#include "operation/operation.h"
#include "save/save.h"
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
      int todo_display_num = 1;
      auto output_todo = [&console, &todo_display_num](Todo &todo)
      {
        console.output_todo(todo, todo_display_num);
        todo_display_num++;
      };
      std::for_each(todos.begin(), todos.end(), output_todo);

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
    case Command::remove:
      try
      {
        unsigned int todo_num = console.get_todo_to_modify(Operation::remove);
        if (todo_num < 0 || todo_num >= todos.size())
        {
          throw InputError("#");
        }
        todos.erase(todos.begin() + todo_num);
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
        unsigned int todo_num = console.get_todo_to_modify(Operation::toggle);
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
      // Braces are required here since we're declaring a variable in this case.
    case Command::write:
    {
      bool save_successful = Save::write(todos);
      console.output_write_status(save_successful);
      console.refresh();
    }
    break;
    case Command::unknown:
      break;
    }
    std::sort(todos.begin(), todos.end());
  }
  return 0;
}
