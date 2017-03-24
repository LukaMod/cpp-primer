#ifndef EX_15_30_QUOTE_H_
#define EX_15_30_QUOTE_H_

#include <string>
#include <iostream>

class Quote
{
  public:
    Quote() {}
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {}
    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {}
    Quote &operator=(const Quote &rhs)
    {
        if (this != &rhs)
        {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        return *this;
    }
    Quote &operator=(Quote &&rhs) noexcept
    {
        if (this != &rhs)
        {
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        return *this;
    }

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
    {
        return n * price;
    }
    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(std::move(*this)); }
    virtual void debug() const;
    virtual ~Quote() = default;

  private:
    std::string bookNo;

  protected:
    double price = 0.0;
};

double print_total(std::ostream &, const Quote &, size_t);

#endif