/**
    @file    fstack.cpp
    @author  Tyler Moses
    @date    04/13/2018
    @version 1.0

    Implementation of a stack test class.
*/
#include <tstack.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <cstring>

// Default Width for columns
const int COLUMN_WIDTH = 35;
// Default Fill Character
const char FILL = '.';
fsu::Stack<int> stack(' ', 1);
fsu::Stack<int> stack1(stack);

/**
 * @name DisplayWelcomeMessage
 * Display a welcome message
 */
void DisplayWelcomeMessage()
{
  std::cout << "This is a Stack < int > test program" << std::endl;
}

/**
 * @name PrintColumn
 * Prints a menu item that is formatted.
 * @param example Function expression.  EX: Pop()
 * @param command User command:         EX: - or 2
 */
void PrintColumn(std::string example, std::string command)
{
  std::cout << std::left << std::setw(COLUMN_WIDTH) << std::setfill(FILL) << example << command << std::endl;
}

/**
 * @name DisplayMenu
 * Displays the menu options
 */
void DisplayMenu()
{
  PrintColumn("Push(Tval) ", " + tval or 1 tval");
  PrintColumn("Pop() ", " - or 2");
  PrintColumn("Clear() ", " C");
  PrintColumn("Top() ", " T");
  PrintColumn("Empty() ", " E");
  PrintColumn("Size() ", " S");
  PrintColumn("Copy Tests ", " =");
  PrintColumn("Display() ", " D");
  PrintColumn("SetOFC(ofc) ", " O 0|b|t|n");
  PrintColumn("SetDIR(+1) ", " < (horizontal -->)");
  PrintColumn("SetDIR(-1) ", " > (vertical   ^  )");
  PrintColumn("Dump() ", " U");
  PrintColumn("Display this menu ", " M");
}

void HandleSelection(char& selection)
{
  switch (selection)
  {
    // Push
    case '1':
    case '+':
      int value;
      std::cin >> value;
      stack.Push(value);
      break;
      // Pop
    case '2':
    case '-':
      stack.Pop();
      break;
      // Clear
    case 'C':
      stack.Clear();
      break;
    case 'T':
      std::cout << "Top of Stack: " << stack.Top() << std::endl;
      break;
    case 'E':
      std::cout << "Stack is ";
      if (!stack.Empty())
        std::cout << "not ";
      std::cout << "empty" << std::endl;
      break;
    case 'S':
      std::cout << std::left << std::setfill(' ') << std::setw(15) << "Stack size" << " = " << stack.Size() << std::endl;
      break;
    case '=':
      std::cout << "CopyTest:\n";
      stack1 = fsu::Stack<int>(stack);
      std::cout << std::left << std::setw(20) << "Copied object\t" << "size: " << stack1.Size() << std::endl;
      std::cout << std::left << std::setw(20) << "" << "contents: ";
      stack1.Display(std::cout);
      std::cout << std::endl;
      break;
    case 'D':
      std::cout << "Stack Contents\t";
      stack.Display(std::cout);
      std::cout << std::endl;
      break;
    case 'O':
      char ofc;
      std::cin >> ofc;
      switch (ofc)
      {
        case 'b':
          ofc = ' ';
          break;
        case 't':
          ofc = '\t';
          break;
        case 'n':
          ofc = '\n';
          break;
        default:
          ofc = '\0';
      }
      stack.SetOFC(ofc);
      break;
    case '<':
      stack.SetDIR(1);
      break;
    case '>':
      stack.SetDIR(-1);
      break;
    case 'U':
      stack.Dump(std::cout);
      break;
    case 'M':
      DisplayMenu();
      break;
    case 'Q':
      std::cout << "\nHave a lovely day.\n";
      break;
    default:
      std::cout << "\n** Unrecognized command -- please try again." << std::endl;
  }
}

int main()
{
  DisplayWelcomeMessage();
  DisplayMenu();

  char selection = 0;
  while (selection != 'Q')
  {
    std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
    std::cin >> selection;
    selection = toupper(selection);
    HandleSelection(selection);
  }
}
