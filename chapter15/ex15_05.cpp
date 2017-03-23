#include "ex15_05.h"

double Bulk_quote::net_price(std::size_t n) const
{
    return (n >= min_qty ? 1 - discount : 1) * n * price;
}
