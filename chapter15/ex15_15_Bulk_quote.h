#ifndef EX_15_15_BULK_QUOTE_H_
#define EX_15_15_BULK_QUOTE_H_

#include "ex15_15_Disc_quote.h"

class Bulk_quote : public Disc_quote
{
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}

    void debug() const override;
    double net_price(std::size_t) const override;
};

#endif