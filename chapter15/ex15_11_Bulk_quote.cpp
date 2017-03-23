#include "ex15_11_Bulk_quote.h"

#include <iostream>

void Bulk_quote::debug() const
{
    Quote::debug();
    std::cout << "min_qty = " << min_qty << "\n"
              << "discount = " << discount << "\n";
}

double Bulk_quote::net_price(std::size_t n) const
{
    return (n >= min_qty ? 1 - discount : 1) * n * price;
}
