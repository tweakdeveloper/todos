// CS200 - Final Project - Nolan Clark - 25JUL24

#pragma once

#include <string>

/// This is a class designed to be thrown when the user provides invalid input.
class InputError
{
private:
  std::string input;

public:
  /// The default constructor for the class, used when we aren't even sure what
  /// the user is trying to do.
  InputError();
  /// A more specific constructor for the class that contains the input the
  /// user provided.
  /// @param input The input provided by the user.
  InputError(std::string input);
  /// Give a short overview of what went wrong.
  /// @returns A user-friendly error message.
  std::string describe();
};
