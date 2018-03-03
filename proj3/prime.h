//
// Created by Tyler Moses on 2/24/18.
//

#ifndef PRIME_H
#define PRIME_H

#include "bitvect.h"
#include <iostream>

class Prime
{
public:
    Prime(size_t n);                                    // Init for number <= n
    size_t Largest(size_t ub) const;                    // Largest prime
    void All (size_t ub, std::ostream& os = std::cout) const; // Display under size
    void All (std::ostream& os = std::cout);            // Print all
    size_t UpperBound  () const;                        // Upper Bounds of current setup
    void ResetUpperBound (size_t ub);                   // Reset size if ub >= UpperBound
    void Dump (std::ostream& os = std::cout) const;     // Dump state
private:
    fsu::BitVector *bv_;                                 // FSU BitVector
    void Sieve();                                       // Initialize bit vector to code primes
};

#endif
