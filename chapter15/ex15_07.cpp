#include "ex15_07.h"

double bk_quote::net_price(std::size_t n) const
{
    if (n > max_qty)
        return max_qty * (1 - discount) * price + (n - max_qty) * price;
    else
        return n * (1 - discount) * price;
}
