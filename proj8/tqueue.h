/**
    @file tqueue.h
    @author Tyler Moses
    @date 04/13/18
    @version 1.0

    Template for a Stack ADT.
*/

#ifndef _TQUEUE_H
#define _TQUEUE_H

#include <iostream>
#include <cstring>
#include <iomanip>

namespace fsu
{
    /**
     * Queue class that utilizes a ring buffer.
     * A ring buffer is a ring of links where the last used link points back to the head.
     *
     * @tparam T Type of ring buffer queue.
     */
    template < typename T >
    class Queue // as ringbuffer
    {
    public:
        // =========================
        // API
        // =========================
        void Push(const T& t);                  // Push an element onto the queue.
        T Pop();                                // Pop an element off the front of the queue.
        T& Front ();                            // Peak at the front element.
        const T& Front() const;                 // Peak at the front element constant version.
        size_t Size() const;                    // Size of the queue.
        bool Empty()  const;                    // Determine if queue contains elements.
        void Clear();                           // Clear the elements in the queue.
        // =========================
        // Extras
        // =========================
        void Append (const Queue& q);           // Append contents of q.
        size_t Capacity() const;                // How many items can be stored.
        void Release();                         // de-allocate all links.
        // =========================
        // Proper Type
        // =========================
        Queue();                                // Default constructor.
        explicit Queue (char ofc);              // Sets output formatting character.
        Queue (const Queue&);                   // Copy constructor.
        ~Queue();                               // Default deconstructor.
        Queue& operator = (const Queue&);       // Override assignment.
        // =========================
        // Display
        // =========================
        void Display (std::ostream& os) const;  // Output queue contents through os - depends on ofc_.
        void SetOFC (char ofc);                 // Set output separator.
        void Dump (std::ostream& os) const;     // Output all private data (Development use only).
    private:
        // =========================
        // Private Display
        // =========================
        char ofc_;                              // Output separator.
        // =========================
        // Private Data
        // =========================
        class Link                              // Link class for chaining data.
        {
            Link (const T& t) : element_(t), next_(nullptr) {}
            T element_;
            Link * next_;
            friend class Queue;
        };
        Link * firstUsed_;                      // Head of the queue.
        Link * firstFree_;                      // One past last item of the queue.
    };
    // class Queue

    // =========================
    // API Implementation
    // =========================

    /**
     * Push an element onto the end of the queue.
     *
     * @tparam T Type of queue.
     * @param t Element to push on the queue.
     */
    template < typename T >
    void Queue<T>::Push(const T& t)
    {
      // Check for null carrier
      if (firstUsed_ == nullptr)
      {
        // Create first used
        firstUsed_ = new Link(t);
        // Create first free
        firstFree_ = new Link(t);
        // firstUsed -> firstFree
        firstUsed_->next_ = firstFree_;
        // firstFree -> firstUsed
        firstFree_->next_ = firstUsed_;
        return;
      }
      // Check if list is full
      if (firstFree_->next_ == firstUsed_)
      {
        // firstFree is T
        firstFree_->element_ = t;
        // append new link to the end
        firstFree_->next_ = new Link(t);
        // set new link to first free
        firstFree_ = firstFree_->next_;
        // reset firstFree -> firstUsed_
        firstFree_->next_ = firstUsed_;
        return;
      }
      // Otherwise
      firstFree_->element_ = t;
      firstFree_ = firstFree_->next_;
    }

    /**
     * Pops an element off the front of the queue.
     *
     * @tparam T Type of queue.
     * @return Front element of the queue popped off.
     */
    template < typename T >
    T Queue<T>::Pop()
    {
      // Handle empty queue.
      if (this->Empty())
      {
        std::cerr << "** Queue error: 'Pop()' called on Empty Queue\n";
        return T();
      }
      // Get element to return
      T element  = firstUsed_->element_;
      // Increment firstUsed_
      firstUsed_ = firstUsed_->next_;
      // Return element
      return element;
    }

    /**
     * TODO Fix exception
     * Take a peak at the first element in the queue.
     * Throws exception if empty.
     *
     * @tparam T Type of queue.
     * @return  First element
     */
    template < typename T >
    T& Queue<T>::Front()
    {
      // Handle empty queue.
      if (this->Empty())
      {
        std::cerr << "** Queue error: 'Front()' called on Empty Queue\n";
      }
      return firstUsed_->element_;
    }

    /**
     * Take a peak at the first element in the queue.
     * Throws exception if empty.
     * Constant version.
     *
     * @tparam T Type of queue.
     * @return  First element
     */
    template < typename T >
    const T& Queue<T>::Front() const
    {
      const T& element = this->Front();
      return element;
    }

    /**
     * Get the size of the queue.
     *
     * @tparam T Type of queue.
     * @return The number of elements being used in the queue.
     */
    template < typename T >
    size_t Queue<T>::Size() const
    {
      if (this->Empty())
        return 0;
      int count = 0;
      Link * runner = firstUsed_;
      while (runner != firstFree_) {
        count++;
        runner = runner->next_;
      }
      return count;
    }

    /**
     * Determine if the queue is empty or not.
     * @tparam T Type of queue.
     * @return boolean: true if empty.
     */
    template < typename T >
    bool Queue<T>::Empty() const
    {
      return firstUsed_ == firstFree_;
    }

    /**
     * Clears the queue but capacity remains the same.
     *
     * @tparam T Type of queue.
     */
    template < typename T >
    void Queue<T>::Clear()
    {
      firstFree_ = firstUsed_;
    }

    // =========================
    // Extras
    // =========================

    /**
     * TODO
     * Append the contents of q to the end of the queue.
     *
     * @tparam T Type of queue.
     * @param q Queue to append.
     */
    template < typename T >
    void Queue<T>::Append(const Queue &q)
    {
      if (!q.Empty())
      {
        Link* runner = q.firstUsed_;
        while (runner != q.firstFree_)
        {
          this->Push(runner->element_);
          runner = runner->next_;
        }
      }
    }

    /**
     * How many items can be stored using existing allocation.
     *
     * @tparam T Type of queue.
     * @return The maximum number of elements.
     */
    template < typename T >
    size_t Queue<T>::Capacity() const
    {
      size_t count = 0;
      Link * runner = firstUsed_;
      while (runner != firstFree_) {
        count++;
        runner = runner->next_;
      }
      return count;
    }

    /**
     * Release the links
     *
     * @tparam T Type of queue.
     */
    template < typename T >
    void Queue<T>::Release()
    {
      Link* pointer = firstUsed_->next_;
      while (firstUsed_ != nullptr) {
        Link* temp = pointer;
        pointer = pointer->next_;
        delete temp;
      }
    }

    // =========================
    // Proper Type Implementations
    // =========================

    /**
     * Default Constructor.
     *
     * @tparam T Type of queue.
     */
    template < typename T >
    Queue<T>::Queue(): ofc_('\0'), firstUsed_(nullptr), firstFree_(nullptr) {}

    /**
     * Constructor that sets output format character.
     *
     * @tparam T Type of queue.
     * @param ofc output format character.
     */
    template < typename T >
    Queue<T>::Queue(char ofc) : ofc_(ofc), firstUsed_(nullptr), firstFree_(nullptr) {}

    /**
     * Copy constructor.
     *
     * @tparam T Type of queue.
     */
    template < typename T >
    Queue<T>::Queue(const Queue<T>& q) : ofc_(q.ofc_)
    {
      if (!q.Empty())
      {
        Link* runner = q.firstUsed_;
        while (runner != q.firstFree_)
        {
          this->Push(runner->element_);
          runner = runner->next_;
        }
      }
    }

    /**
     * Default de-constructor.
     *
     * @tparam T Type of queue.
     */
    template < typename T >
    Queue<T>::~Queue()
    {
      this->Release();
      delete this;
    }

    /**
     * Assignment override
     *
     * @tparam T Type of queue.
     * @param q queue being assigned.
     * @return assigned queue.
     */
    template < typename T >
    Queue<T>& Queue<T>::operator = (const Queue<T>& q)
    {
      this->ofc_ = q.ofc_;
      this->firstFree_ = q.firstFree_;
      this->firstUsed_ = q.firstUsed_;
      return *this;
    }

    // =========================
    // Display Implementation
    // =========================

    /**
     * Display the elements of the queue.
     *
     * @tparam T Type of queue.
     * @param os output stream.
     */
    template < typename T >
    void Queue<T>::Display(std::ostream &os) const
    {
      // Check for null container
      if (firstUsed_ == nullptr)
        return;
      Link * pointer = firstUsed_;
      // While we are not at first free
      while (pointer != firstFree_) {
        // Check output character
        if (ofc_ != '\0')
          os << ofc_;
        // Output the element
        os << pointer->element_;
        // Move to the next one.
        pointer = pointer->next_;
      }
    }

    /**
     * Set the output separator to the given character.
     *
     * @tparam T Type of queue.
     * @param ofc output format character.
     */
    template < typename T >
    void Queue<T>::SetOFC(char ofc) { ofc_ = ofc; }

    /**
     * Dump all stack elements.
     *
     * @tparam T Type of queue.
     * @param os output stream.
     */
    template < typename T >
    void Queue<T>::Dump(std::ostream &os) const
    {
      // Check for null container
      if (firstUsed_ == nullptr)
        return;
      Link * pointer = firstUsed_;
      // While we are not at first free
      while (pointer->next_ != firstUsed_) {
        // Check output character
        if (ofc_ != '\0')
          os << ofc_;
        // Output the element
        os << pointer->element_;
        // Move to the next one.
        pointer = pointer->next_;
      }
      // Check output character
      if (ofc_ != '\0')
        os << ofc_;
      // Output the element
      os << pointer->element_;
    }

    // =========================
    // More Extras
    // =========================

    /**
     * Override output pipe for Queue.
     * Now uses Display method instead.
     *
     * @tparam T Type of queue.
     * @param os output stream.
     * @param q Queue.
     * @return output stream.
     */
    template < typename T >
    std::ostream& operator << (std::ostream& os, const Queue<T>& q)
    {
      q.Display(os);
      return os;
    }
}
// namespace fsu

#endif //_TQUEUE_H
