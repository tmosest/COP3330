/**
    @file    product.cpp
    @author  Tyler Moses
    @date    02/03/2018
    @version 1.0

    Implementation of a product class.
*/
#include <product.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <cstring>

/**
 * Function to create a new default Product.
 * Name is set to "#"
 * Code is set to 0x00000000
 * Cost is set to 0.0
 */
Product::Product(): code_(0x00000000), cost_(0.0)
{
  SetName("#");
}

/**
 * Function to create a new Product with all three arguments.
 * @param name The name of the product.
 * @param code The product's bar code.
 * @param price The price of the product.
 */
Product::Product(const char * name, uint32_t code, float price)
        : code_(code), cost_(price)
{
  SetName(name);
}

/**
 * Function to create a  copy of a product.
 * @param p Reference to another product.
 */
Product::Product(const Product& p)
        : code_(p.GetBarCode()), cost_(p.GetCost())
{
  SetName(p.GetName());
}

/**
 * Function to set the name to the copy of a string.
 * @param name String to copy.
 */
void Product::SetName(const char * name)
{
  name_ = new char[std::strlen(name)];
  std::strcpy(name_, name);
}

/**
 * Set the cost of the product.
 * @param cost Float price.
 */
void Product::SetCost(float cost)
{
  cost_ = cost;
}

/**
 * Set the bar code value.
 * @param code uint32_t code.
 */
void Product::SetBarCode(uint32_t code)
{
  code_ = code;
}

/**
 * Get the product's name.
 * @return return pointer to name.
 */
const char * Product::GetName() const
{
  return name_;
}

/**
 * Get the product's bar code.
 * @return uint32_t barcode.
 */
uint32_t Product::GetBarCode() const
{
  return code_;
}

/**
 * Get the cost of the product.
 * @return Float cost.
 */
float Product::GetCost() const
{
  return cost_;
}

/**
 * Function to override the output operator.
 * @param os output stream.
 * @param p Product reference.
 * @return os output stream.
 */
std::ostream& operator << ( std::ostream& os , const Product& p)
{
  std::ios_base::fmtflags flags = os.flags();
  os.setf(std::ios::fixed | std::ios::showpoint); // prep for $ output
  os.precision(2);
  os << p.GetName() << '\t'
     << std::hex << std::uppercase << std::setfill('0') << std::setw(8) // prep for hex output
     << p.GetBarCode()
     << std::dec << std::setfill(' ') << '\t'          // return dec output
     << p.GetCost();
  os.setf(flags); // return flags to previous states
  return os;
}
