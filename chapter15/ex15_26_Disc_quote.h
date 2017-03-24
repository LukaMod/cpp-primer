#ifndef EX_15_26_DISC_QUOTE_H_
#define EX_15_26_DISC_QUOTE_H_

#include "ex15_26_Quote.h"

class Disc_quote : public Quote
{
  public:
    Disc_quote() { std::cout << "Disc_quote()" << std::endl; }
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc)
    {
        std::cout << "Disc_quote(const string&, double, size_t, double)" << std::endl;
    }
    Disc_quote(const Disc_quote &dq) : Quote(dq), quantity(dq.quantity), discount(dq.discount)
    {
        std::cout << "Disc_quote(const Disc_quote&)" << std::endl;
    }
    Disc_quote &operator=(const Disc_quote &rhs)
    {
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
        std::cout << "operator=(const Disc_quote&)" << std::endl;
        return *this;
    }
    Disc_quote(Disc_quote &&dq) noexcept : Quote(std::move(dq))
    {
        quantity = std::move(quantity);
        discount = std::move(discount);
        std::cout << "Disc_quote(Disc_quote&&)" << std::endl;
    }
    Disc_quote &operator=(Disc_quote &&rhs) noexcept
    {
        if (this != &rhs)
        {
            Quote::operator=(std::move(rhs));
            quantity = std::move(rhs.quantity);
            discount = std::move(rhs.discount);
        }
        std::cout << "operator=(Disc_quote&&)" << std::endl;
        return *this;
    }

    double net_price(std::size_t) const = 0;

  protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

#endif // !DISC_QUOTE_H_
