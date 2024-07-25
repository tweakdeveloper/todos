// CS200 - Final Project - Nolan Clark - 25JUL24

#include <iostream>

#include "todo/todo.h"

using namespace std;

int main()
{
  cout << boolalpha;
  Todo sample_todo("say hi!");
  cout << "Priority\tTitle\tCompleted\n"
       << sample_todo.get_priority() << "\t"
       << sample_todo.get_title() << "\t"
       << sample_todo.has_been_completed() << endl;
  return 0;
}
