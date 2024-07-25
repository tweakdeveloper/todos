// CS200 - Final Project - Nolan Clark - 25JUL24

#include <string>

#include "input_error.h"

InputError::InputError() : input("¿?")
{
}

InputError::InputError(std::string input) : input(input)
{
}

std::string InputError::describe()
{
  return "Unable to interpret input " + input;
}
