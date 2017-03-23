#ifndef EX_15_16_H_
#define EX_15_16_H_

#include "ex15_15_Disc_quote.h"

class bk_quote : public Disc_quote
{
  public:
    bk_quote() = default;
    bk_quote(const std::string &book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}

    double net_price(std::size_t) const override;
    void debug() const override;
};

#endif