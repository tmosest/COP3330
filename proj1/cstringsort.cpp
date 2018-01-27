/**
    @file    cstringsort.cpp
    @author  Tyler Moses
    @date    01/27/2018
    @version 1.0

    Implementation of string sorting functions
*/

#include <cstringsort.h>
#include <cstdlib>
#include <cstring>

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
  if (size < 2) return;
}