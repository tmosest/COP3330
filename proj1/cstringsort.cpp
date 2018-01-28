/**
    @file    cstringsort.cpp
    @author  Tyler Moses
    @date    01/27/2018
    @version 1.0

    Implementation of string sorting functions
*/

#include <cstringsort.h>
#include <cstringdiff.h>
#include <cstdlib>

/**
 * Function to sort a string based on the Lexicon ordering.
 * The 32 control characters are (0 - 31).
 * The 96 visible characters are (32 - 127).
 * This method can also be extended to work for EXTENDED_ASCII and UNICODE16.
 * Uses Insertion Sort.
 * @param beg Pointer to the start of the string array.
 * @param end Pointer to the end of the string array.
 */
void LexStringSort  (char* beg[], char* end[]) {
  std::size_t size = end - beg; // size of the array
  if (size < 2) return; // nothing to do
  std::size_t i; // outer loop control
  std::size_t j; // inner loop control
  std::size_t k; // always j - 1
  char * t; // string holder
  for (i = 0; i < size; ++i)
  {
    t = beg[i];
    for (k = i, j = k--; j > 0 && LexComp(t, beg[k]); --j, --k)
      beg[j] = beg[k];
    beg[j] = t;
  }
}

/**
 * Function to sort a string based on the Dictionary ordering.
 * Pretty much the same as LexStringSort, but letter case is ignored.
 * Uses Insertion Sort.
 * @param beg Pointer to the start of the string array.
 * @param end Pointer to the end of the string array.
 */
void DictionaryStringSort (char* beg[], char *end[]) {
  std::size_t size = end - beg; // size of the array
  if (size < 2) return; // nothing to do
  std::size_t i; // outer loop control
  std::size_t j; // inner loop control
  std::size_t k; // always j - 1
  char * t; // string holder
  for (i = 0; i < size; ++i)
  {
    t = beg[i];
    for (k = i, j = k--; j > 0 && DictionaryComp(t, beg[k]); --j, --k)
      beg[j] = beg[k];
    beg[j] = t;
  }
}