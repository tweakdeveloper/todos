// CS200 - Final Project - Nolan Clark - 25JUL24

#include <iostream>

#include "console/console.h"
#include "todo/todo.h"

using namespace std;

int main()
{
  Console console;
  Todo sample_todo("say hi!");
  console.output_todo(sample_todo);
  return 0;
}
