// CS200 - Final Project - Nolan Clark - 25JUL24

#include <iostream>

#include "console/console.h"
#include "todo/todo.h"

using namespace std;

int main()
{
  Console console;
  console.output_help();
  while (true)
  {
    Command user_desire = console.get_user_desire();
    if (user_desire == Command::quit)
    {
      break;
    }
  }
  return 0;
}
