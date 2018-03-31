/**
    @file    cstringdiff.h
    @author  Tyler Moses
    @date    01/27/2018
    @version 1.0

    Header file for different way to compute string difference.
*/

/**
 * Function to compute the Lexicon value difference between two strings.
 * Uses an Arithmetic approach instead of a Logic approach.
 * Examples:
 *      -1 = LexDiff(abc,acz) #  -1  = (int)'b' - (int)'c'
 *      -23 = LexDiff(abc,abz) # -23  = (int)'c' - (int)'z'
 *      +3 = LexDiff(abf,abc) #  +3  = (int)'f' - (int)'c'
 *       0 = LexDiff(abc,abc)
 *      -99 = LexDiff(ab,abc)  # -99  = (int)'\0' - (int)'c'
 *      +99 = LexDiff(abc,ab)  # +99  = (int)'c' - (int)'\0'
 *      +31 = LexDiff(abc,abD)
 *      -1 = LexDiff(abc,abd)
 *      -32 = LexDiff(aBc,abc) # -32  = (int)'B' - (int)'b'
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @return integer difference in lexicon value at first non-matching character.
 */
int  LexDiff  (const char* s1, const char* s2);

/**
 * Function to compute the Dictionary difference between two strings.
 * Uses a Logic approach instead of a Arithmetic one.
 * Examples:
 *      -1 = DictionaryDiff(abc,acz) # 'b' comes before 'c' in ascii order
 *      -1 = DictionaryDiff(abc,abz) # 'c' comes before 'z' in ascii order
 *      +1 = DictionaryDiff(abf,abc) # 'f' comes after 'c' in ascii order
 *       0 = DictionaryDiff(abc,abc)
 *      -1 = DictionaryDiff(ab,abc)
 *      +1 = DictionaryDiff(abc,ab)
 *      -1 = DictionaryDiff(abc,abD) # 'c' comes before 'd' in ascii order
 *      -1 = DictionaryDiff(abc,abd)
 *       0 = DictionaryDiff(aBc,abc)
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @return -1 if s1 < s1, 0 if s1 = s2 and, 1 if s1 > s2
 */
int DictionaryDiff  (const char* s1, const char* s2);

/**
 * Compares two strings using the LexDiff function.
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @return True if s1 < s2.
 */
bool  LexComp (const char* s1, const char* s2);

/**
 * Compares two strings using the DictionaryDiff function.
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @return True if s1 < s2.
 */
bool  DictionaryComp (const char* s1, const char* s2);