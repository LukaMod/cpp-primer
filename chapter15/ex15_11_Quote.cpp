#include "ex15_11_Quote.h"

#include <iostream>

void Quote::debug() const
{
    std::cout << "data members of this class:\n"
              << "bookNo = " << bookNo << "\n"
              << "price = " << price << "\n";
}
