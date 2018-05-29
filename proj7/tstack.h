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
#include <cstring>
#include <iomanip>

namespace fsu
{
    /**
     * @name Stack
     * Abstract DataType that represents a Stack.
     * @tparam T Type of Stack.
     * @tparam N Capacity of the Stack.
     */
    template<typename T, size_t N = 100>
    class Stack
    {
    private:
        // =========================
        // Data
        // =========================
        const size_t capacity_;                 // Maximum Capacity.
        T *data_;                               // Dynamically allocated array.
        size_t size_;                           // Current Size of the stack.
        // =========================
        // Display
        // =========================
        char ofc_;
        int dir_;
    public:
        // =========================
        // API
        // =========================
        void Push(const T &t);                  // Push t onto the stack.
        T Pop();                                // Pop stack and remove the element; error if empty.
        T& Top();                               // Return top element of the the stack; error if empty.
        const T& Top() const;                   // const version
        size_t Size() const;                    // return the number of elements in the stack.
        size_t Capacity() const;                // return the max size of the stack.
        bool Empty() const;                     // 1 if the stack is empty, 0 otherwise.
        void Clear();                           // make the stack empty.
        // =========================
        // Constructor / Destructor
        // =========================
        Stack();                                // Default Constructor.
        Stack(char ofc, int dir);               // Sets  ofc_ and dir_.
        Stack(const Stack &);                   // Copy Constructor.
        ~Stack();                               // Default Deconstructor.
        Stack &operator=(const Stack &);        // Assignment Operator.
        // =========================
        // Display
        // =========================
        void Display(std::ostream &os) const;   // Output stack contents.
        void SetOFC(char ofc);                  // Set OFC
        void SetDIR(int dir);                   // Set DIR
        void Dump(std::ostream &os);            // Output all private data.
    };
    // end Stack template

    // =========================
    // API
    // =========================

    /**
     * @name Push
     * Add an element to the top of the stack.
     * @tparam T
     * @tparam N
     * @param t
     */
    template<typename T, size_t N>
    void Stack<T, N>::Push(const T &t)
    {
        if (size_ + 1 < capacity_)
        {
            data_[size_++] = t;
            return;
        }
        std::cerr << "** Stack error: Push(" << t << ") called on full stack\n";
    }

    /**
     * @name Pop
     * Returns the top element of the stack.
     * @tparam T
     * @tparam N
     * @return
     */
    template<typename T, size_t N>
    T Stack<T, N>::Pop()
    {
        if (!this->Empty())
            return data_[size_--];
        std::cerr << "** Stack error: Pop() called on Empty Stack\n";
        return data_[0];
    }

    /**
     * @name Top
     * Look at the top element in the stack without popping it.
     * Logs an error for overflow!
     * @tparam T Type of the Stack
     * @tparam N Capacity of the Stack
     * @return Top element.
     */
    template<typename T, size_t N>
    T& Stack<T, N>::Top()
    {
        if (!this->Empty())
            return data_[size_];
        std::cerr << "** Stack error: Pop() called on Empty Stack\n";
        return data_[0];
    }

    /**
     * @name Top
     * Look at the top element in the stack without popping it.
     * Logs an error for overflow!
     * Constant Version
     * @tparam T Type of the Stack
     * @tparam N Capacity of the Stack
     * @return Top element
     */
    template<typename T, size_t N>
    const T& Stack<T, N>::Top() const
    {
        if (!this->Empty())
            return data_[size_];
        std::cerr << "** Stack error: Pop() called on Empty Stack\n";
        return data_[0];
    }

    /**
     * @name Size
     * Gets the current size of the Stack.
     * @tparam T Type of the Stack
     * @tparam N Capacity of the Stack
     * @return Size of the Stack
     */
    template<typename T, size_t N>
    size_t Stack<T, N>::Size() const
    {
        return size_;
    }

    /**
     * @name Capacity
     * Gets the maximum size of the Stack.
     * @tparam T Type of the Stack
     * @tparam N Capacity of the Stack
     * @return Capacity of the Stack
     */
    template<typename T, size_t N>
    size_t Stack<T, N>::Capacity() const
    {
        return capacity_;
    }

    /**
     * @name Empty
     * Determines if the stack is empty or not.
     * @tparam T Type of the Stack
     * @tparam N Capacity of the Stack
     * @return True if empty
     */
    template<typename T, size_t N>
    bool Stack<T, N>::Empty() const
    {
        size_t empty = 0;
        return size_ == empty;
    }

    /**
     * @name Clear
     * Clears the stack.
     * @tparam T Type of the Stack
     * @tparam N Capacity of the Stack
     */
    template<typename T, size_t N>
    void Stack<T, N>::Clear()
    {
        delete data_;
        data_ = new T[capacity_];
        size_ = 0;
    }

    // =========================
    // Constructor / Destructor
    // =========================

    /**
     * @name Stack
     * Default Constructor.
     * @tparam T Type of the Stack
     * @tparam N Capacity of the Stack
     */
    template<typename T, size_t N>
    Stack<T, N>::Stack() : capacity_(N), size_(0), ofc_('\0'), dir_(1)
    {
      data_ = new T[capacity_];
    }

    /**
     * @name Stack(char ofc, int dir)
     * Constructor with output options.
     * @tparam T Type of Stack
     * @tparam N Capacity of the Stack
     * @param ofc Seperator Character
     * @param dir Direction of Stack for Printing
     */
    template <typename T, size_t N>
    Stack<T, N>::Stack(char ofc, int dir) : capacity_(N), size_(0), ofc_(ofc), dir_(dir)
    {
        data_ = new T[capacity_];
    }

    /**
     * @name Stack(const Stack &stack)
     * Copy constructor for the stack
     * @tparam T Type of Stack
     * @tparam N Capacity of the Stack
     * @param stack Stack to copy
     */
    template <typename T, size_t N>
    Stack<T, N>::Stack(const Stack<T, N>& stack) : capacity_(stack.capacity_)
    {
        size_ = stack.size_;
        data_ = new T[capacity_];
        ofc_ = stack.ofc_;
        dir_ = stack.dir_;
        for (size_t i = 0; i < size_; i++)
        {
            std::cout << "\n";
            data_[i] = stack.data_[i];
        }
    }

    /**
     * @name ~Stack
     * Default Deconstructor
     * @tparam T Type of Stack
     * @tparam N Capacity of the Stack
     */
    template <typename T, size_t N>
    Stack<T, N>::~Stack()
    {
        delete data_;
    }

    /**
     * @name =
     * Equals operator.
     * @tparam T Type of Stack
     * @tparam N Capacity of the Stack
     * @param s Stack to be assigned to.
     * @return Assigned stack
     */
    template <typename T, size_t N>
    Stack<T,N>& Stack<T, N>::operator=(const Stack &s)
    {
        this->ofc_ = s.ofc_;
        this->dir_ = s.dir_;
        this->data_ = s.data_;
        this->size_ = s.size_;
        return *this;
    }

    // =========================
    // Display
    // =========================

    /**
     * @name Display
     * Displays the contents of the stack based on the dir and ofc.
     * Positive dir indicate bottom-up vs top-down for negative.
     * The ofc character is used to separate each item.
     * @tparam T Type of Stack
     * @tparam N Capacity of the Stack
     * @param os Output Stream.
     */
    template<typename T, size_t N>
    void Stack<T, N>::Display(std::ostream &os) const
    {
        // dir_determines the print ordering
        if (dir_ < 0)
        {
            // Top to Bottom Ordering
            for (int i = size_ -  1; i > -1; i--)
            {
                if (ofc_ != '\0')
                    os << ofc_;
                os << data_[i];
            }
        }
        else
        {
            // Bottom Up Ordering
            for (size_t i = 0; i < size_; i++)
            {
                if (ofc_ != '\0')
                    os << ofc_;
                os << data_[i];
            }
        }
    }

    /**
     * @name SetOFC
     * @tparam T Type of Stack
     * @tparam N Capacity of the Stack
     * @param ofc Char for Display separation
     */
    template<typename T, size_t N>
    void Stack<T, N>::SetOFC(char ofc)
    {
        ofc_ = ofc;
    }

    /**
     * @name SetDIR
     * Sets the direction of the Stack for printing.
     * @tparam T Type of Stack
     * @tparam N Capacity of the Stack
     * @param dir positive for bottom-up, negative for top-down
     */
    template<typename T, size_t N>
    void Stack<T, N>::SetDIR(int dir)
    {
        dir_ = dir;
    }

    /**
     * @name Dump
     * Dumps the contents of the Stack.
     * @tparam T Type of Stack
     * @tparam N Capacity of the Stacks
     * @param os output stream
     */
    template<typename T, size_t N>
    void Stack<T, N>::Dump(std::ostream &os)
    {
        os << std::left << std::setfill(' ') << std::setw(15) << "Capacity:" << this->capacity_ << std::endl;
        os << std::left << std::setfill(' ') << std::setw(15) << "Size:" << this->Size() << std::endl;
        // TODO print array
        os << std::left << std::setfill(' ') << std::setw(15) << "Array:" << "[";
        for (std::size_t i = 0; i < capacity_; i++)
        {
            os << data_[i];
            if (i != capacity_ - 1)
                os << ",";
        }
        os << "]" <<  std::endl;
        os << std::left << std::setfill(' ') << std::setw(15) << "Stack:" << "[";
        for (std::size_t i = 0; i < size_; i++)
        {
            os << data_[i];
            if (i != size_ - 1)
                os << ",";
        }
        os << "]" << std::endl;
    }

    /**
     * @name <<
     * Override Stack output to Display
     * @tparam T Type of Stack
     * @tparam N Capacity of the Stack
     * @param os output stream
     * @param s Stacl
     * @return output stream
     */
    template<typename T, size_t N>
    std::ostream& operator << (std::ostream& os, const Stack<T,N>& s)
    {
        s.Display(os);
        return os;
    }
}
// end namespace fsu

#endif
