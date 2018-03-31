/**
    @file tsort.h
    @author Tyler Moses
    @date 03/31/18
    @version 1.0

    Introduction to template functions.
*/

#ifndef _TSORT_H
#define _TSORT_H

#include <iostream>

/**
 * Template for displaying data.
 * [beg, end)
 * @tparam T Type of elements.
 * @param beg The beginning of the interval.
 * @param end The beginning of the interval.
 * @param ofc Character to put between each value in the range.
 */
template < typename T >
void Display (const T* beg, const T* end, char ofc = '\0')
{
  // Loop through the element array
  while (beg != end)
  {
    // Output the element
    std::cout << *beg;
    // If ofc is not null terminator
    // Print it
    if (ofc != '\0')
      std::cout << ofc;
    // Increment pointer
    ++beg;
  }
}

/**
 * Utility function for swapping
 * @tparam T Type of elements.
 * @param t1 First Element.
 * @param t2 Second Element.
 */
template <typename T>
void Swap (T& t1, T& t2)
{
  T temp;
  temp = t1;
  t1 = t2;
  t2 = temp;
}

/**
 * Template for insertion sort.
 * [beg, end)
 * Insertion sort is a simple sorting algorithm.
 * https://en.wikipedia.org/wiki/Insertion_sort
 * Already sorted O(n).
 * Worst case O(n^2).
 * More efficient than mergesort and other n lg n sorting algorithms
 * for a small number of elements.
 * @tparam T Type of elements.
 * @param beq The beginning of the interval.
 * @param end The end of the interval.
 */
template < typename T >
void InsertionSort(T* beq, T* end)
{
  // Start at index 1
  T * i = (beq + 1);
  // Run i up to length
  while (i < end)
  {
    // Look at J
    T * j =  i;
    // Run j down and swap if can
    while (j > beq && *(j) < *(j - 1))
    {
      // Swap
      Swap(*j, *(j - 1));
      // Down j
      --j;
    }
    // Up i
    ++i;
  }
}

#endif
