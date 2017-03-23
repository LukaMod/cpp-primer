#include "ex15_15_Bulk_quote.h"

#include <iostream>

void Bulk_quote::debug() const
{
    Quote::debug();
    std::cout << "min_qty = " << quantity << "\n"
              << "discount = " << discount << "\n";
}

double Bulk_quote::net_price(std::size_t n) const
{
    return (n >= quantity ? 1 - discount : 1) * n * price;
}
