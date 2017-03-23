#include "ex15_16.h"

#include <iostream>

double bk_quote::net_price(std::size_t n) const
{
    if (n > quantity)
        return quantity * (1 - discount) * price + (n - quantity) * price;
    else
        return n * (1 - discount) * price;
}

void bk_quote::debug() const
{
    Quote::debug();
    std::cout << "quantity = " << quantity << "\n"
              << "discount = " << discount << "\n";
}
