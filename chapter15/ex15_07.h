#ifndef EX_15_07_H_
#define EX_15_07_H_

#include "ex15_03.h"

class bk_quote : public Quote
{
  public:
    bk_quote() = default;
    bk_quote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), max_qty(qty), discount(disc) {}

    double net_price(std::size_t) const override;

  private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

#endif