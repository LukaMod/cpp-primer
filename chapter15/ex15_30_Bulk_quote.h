#ifndef BULK_QUOTE_H_
#define BULK_QUOTE_H_

#include "ex15_15_Disc_quote.h"

class Bulk_quote : public Disc_quote
{
  public:
    using Disc_quote::Disc_quote;

    Bulk_quote() {}
    Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) {}
    Bulk_quote &operator=(const Bulk_quote &rhs)
    {
        Disc_quote::operator=(rhs);
        return *this;
    }
    Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(bq) {}
    Bulk_quote &operator=(Bulk_quote &&rhs) noexcept
    {
        Disc_quote::operator=(std::move(rhs));
        return *this;
    }

    void debug() const override;
    double net_price(std::size_t) const override;
    Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
    Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
};

#endif