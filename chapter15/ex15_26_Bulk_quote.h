#ifndef EX_15_26_BULK_QUOTE_H_
#define EX_15_26_BULK_QUOTE_H_

#include "ex15_26_Disc_quote.h"

class Bulk_quote : public Disc_quote
{
  public:
    Bulk_quote() { std::cout << "Bulk_quote()" << std::endl; }
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc)
    {
        std::cout << "Bulk_quote(const string&, double, size_t, double)" << std::endl;
    }
    Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq)
    {
        std::cout << "Bulk_quote(const Bulk_quote&)" << std::endl;
    }
    Bulk_quote &operator=(const Bulk_quote &rhs)
    {
        Disc_quote::operator=(rhs);
        std::cout << "operator=(const Bulk_quote&)" << std::endl;
        return *this;
    }
    Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(bq)
    {
        std::cout << "Bulk_quote(Bulk_quote&&)" << std::endl;
    }
    Bulk_quote &operator=(Bulk_quote &&rhs) noexcept
    {
        Disc_quote::operator=(std::move(rhs));
        std::cout << "operator=(Bulk_quote&&)" << std::endl;
        return *this;
    }

    void debug() const override;
    double net_price(std::size_t) const override;
};

#endif