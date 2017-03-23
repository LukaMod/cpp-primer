#ifndef EX_15_05_H_
#define EX_15_05_H_

#include "ex15_03.h"

class Bulk_quote : public Quote
{
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}

    double net_price(std::size_t) const override;

  private:
    std::size_t min_qty = -1;
    double discount = 0.0;
};

#endif