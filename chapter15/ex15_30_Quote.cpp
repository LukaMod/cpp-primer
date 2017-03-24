#include "ex15_30_Quote.h"

#include <iostream>

void Quote::debug() const
{
    std::cout << "data members of this class:\n"
              << "bookNo = " << bookNo << "\n"
              << "price = " << price << "\n";
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n
       << " total due: " << ret << std::endl;
    return ret;
}
