//
// Created by Tyler Moses on 2/24/18.
//

#include "prime.h"
#include "bitvect.h"
#include <iostream>

typedef fsu::BitVector BitVector;

Prime::Prime(size_t n)
{
  this->bv_ = new BitVector (n + 1);
  this->Sieve();
}

void Prime::Sieve()
{
  size_t length = bv_->Size();
  // This should always be true
  // But it acts as an init check
  if (length > 2)
  {
    bv_->Set();
    bv_->Unset(0);
    bv_->Unset(1);
    // Loop through all from 2
    for (size_t i = 2; i < bv_->Size(); i++)
    {
      // If the bit is 1
      // Then it is prime
      if(bv_->Test(i))
      {
        // We loop through and update other bits
        int mult = 2;
        while (i * mult < length)
        {
          // Update multiplied bit index
          bv_->Unset(i * mult);
          // increase amount to multiply by
          ++mult;
        } // end while
      } // end if
    }
  }
    // Then all we have is 0 and 1 which are not prime
  else
  {
    // So make 0 0 to say 0 and 1 are not prime
    bv_->Unset();
  }
}

size_t Prime::Largest(size_t ub) const
{
  if (ub >= bv_->Size())
  {
    // TODO throw some sort of error.
  } else {
    for (size_t i = ub; i >= 2; i--) {
      if (bv_->Test(i))
      {
        return i;
      }
    }
  }
  return (ub < 2) ? 0 : 2;
}

void  Prime::Dump (std::ostream& os) const
{
  bv_->Dump(os);
}

void Prime::All (size_t ub, std::ostream& os) const
{
  for (int i = 2; i <= ub; i++)
  {
    if (bv_->Test(i))
    {
      os << i << " ";
    }
  }
}

void Prime::All (std::ostream& os)
{
  for (int i = 2; i < bv_->Size(); i++)
  {
    if (bv_->Test(i))
    {
      os << i << " ";
    }
  }
}

size_t Prime::UpperBound  () const
{
  return bv_->Size() - 1;
}

void Prime::ResetUpperBound (size_t ub)
{
  size_t length = bv_->Size();
  if (ub > length)
  {
    bv_->Expand(ub - length + 1);
    this->Sieve();
  }
}