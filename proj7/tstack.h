/**
    @file tstack.h
    @author Tyler Moses
    @date 04/13/18
    @version 1.0

    Template for a Stack ADT.
*/

#ifndef _TSTACK_H
#define _TSTACK_H

#include <iostream>

namespace fsu
{
  /**
   * @name Stack
   * Abstract DataType that represents a Stack.
   * @tparam T
   * @tparam N
   */
  template <typename T, size_t N = 100>
  class Stack
  {
    private:
      // =========================
      // Data
      // =========================
      const size_t capacity_;                // Maximum Capacity.
      T * data_;                             // Dynamically allocated array.
      size_t size_;                          // Current Size of the stack.
      // =========================
      // Display
      // =========================
      char ofc_;
      int dir_;
    public:
      // =========================
      // API
      // =========================
      void Push(const T& t);                 // Push t onto the stack.
      T Pop();                               // Pop stack and remove the element; error if empty.
      T& Top();                              // Return top element of the the stack; error if empty.
      const T& Top() const;                  // const version
      size_t Size() const;                   // return the number of elements in the stack.
      size_t Capacity() const;               // return the max size of the stack.
      bool Empty() const;                    // 1 if the stack is empty, 0 otherwise.
      void Clear() const;                    // make the stack empty.
      // =========================
      // Constructor / Destructor
      // =========================
      Stack();                               // Default Constructor.
      Stack(char ofc, int dir);              // Sets  ofc_ and dir_.
      Stack(const Stack&);                   // Copy Constructor.
      ~Stack();                              // Default Deconstructor.
      Stack& operator = (const Stack&);      // Assignment Operator.
      // =========================
      // Display
      // =========================
      void Display (std::ostream& os) const; // Output stack contents.
      void SetOFC(char ofc);                 // Set OFC
      void SetDIR(int dir);                  // Set DIR
      void Dump(std::ostream& os);           // Output all private data.
  };
  // end Stack template
}
// end namespace fsu

#endif
