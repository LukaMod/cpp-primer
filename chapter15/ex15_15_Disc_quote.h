#ifndef EX_15_15_DISC_QUOTE_H_
#define EX_15_15_DISC_QUOTE_H_

#include "ex15_11_Quote.h"

class Disc_quote : public Quote
{
  public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}

    double net_price(std::size_t) const = 0;

  protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

#endif // !DISC_QUOTE_H_
