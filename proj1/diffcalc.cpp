/*
    sdiff.cpp
    01/02/18
    Chris Lacher

    Driver program for stringsort project
    Sorting C-strings from a file

    Reads C-strings redirected from a file and sorts them

    Copyright 2018, R.C. Lacher
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstringdiff.h>

int main(int argc, char* argv[])
{
  if (argc < 3)
  {
    std::cout << " ** Two string arguments required - try again\n";
    exit (EXIT_FAILURE);
  }
  std::cout << " LexDiff(s1,s2) = " << LexDiff(argv[1],argv[2]) << '\n'
            << " DicDiff(s1,s2) = " << DictionaryDiff(argv[1],argv[2]) << '\n';
  return (EXIT_SUCCESS);
}

