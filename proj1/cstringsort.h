/**
    @file    cstringsort.h
    @author  Tyler Moses
    @date    01/27/2018
    @version 1.0

    Header file for string sorting functions
*/

/**
 * Function to sort a string based on the Lexicon ordering.
 * The 32 control characters are (0 - 31).
 * The 96 visible characters are (32 - 127).
 * This method can also be extended to work for EXTENDED_ASCII and UNICODE16.
 * @param beg Pointer to the start of the string array.
 * @param end Pointer to the end of the string array.
 */
void LexStringSort  (char* beg[], char* end[]);

/**
 * Function to sort a string based on the Dictionary ordering.
 * Pretty much the same as LexStringSort, but letter case is ignored.
 * @param beg Pointer to the start of the string array.
 * @param end Pointer to the end of the string array.
 */
void DictionaryStringSort (char* beg[], char *end[]);