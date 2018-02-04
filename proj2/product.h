/**
    @file    product.h
    @author  Tyler Moses
    @date    02/03/2018
    @version 1.0

    Header file for a product class.
*/
#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdint>

class Product
{
public:
  Product ();                              // Constructor with no arguments
  Product (const char *, uint32_t, float); // Constructor with 3 arguments
  Product (const Product  &p);             // Copy
  void SetName (const char *);             // sets the name field
  void SetBarCode (uint32_t);              // sets the bar code
  void SetCost (float);                    // sets the cost
  const char * GetName() const;            // returns a const pointer to the name field
  uint32_t GetBarCode() const;             // returns the bar code by value
  float GetCost() const;                   // returns the cost by value
private:
  char * name_;                            // the product name
  uint32_t code_;                          // the product bar code
  float cost_;                             // the product cost
};

std::ostream& operator << ( std::ostream& os , const Product& p);

#endif
