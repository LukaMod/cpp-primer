#ifndef EX_15_11_BULK_QUOTE_H_
#define EX_15_11_BULK_QUOTE_H_

#include "ex15_11_Quote.h"

class Bulk_quote : public Quote
{
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}

    void debug() const override;
    double net_price(std::size_t) const override;

  private:
    std::size_t min_qty = -1;
    double discount = 0.0;
};

#endif