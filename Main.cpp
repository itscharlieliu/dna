/**
Charlie Liu
2274468
liu305@mail.chapman.edu
CPSC350-2
Assignment1

This source file is where the user is asked to input the name of the file being processed.
*/

#include "Dna.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  Dna d;

  bool loop = true;

  while (loop)
  {
  cout << "What is the name of the file you want to process?\n";
  string userInput;

  getline(cin, userInput);
  d.readFile(userInput);

  d.outputData("charlieliu.out");

  bool invalidInput = true;
  while (invalidInput)
  {
    cout << "Would you like to process another list? y/n\n";
    getline(cin, userInput);
    if (userInput == "Y" || userInput == "y")
    {
      invalidInput = false;
    }
    if (userInput == "N" || userInput == "n")
    {
      invalidInput = false;
      loop = false;
    }
  }

  }

  return 0;
}
