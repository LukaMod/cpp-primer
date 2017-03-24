#ifndef EX_15_26_QUOTE_H_
#define EX_15_26_QUOTE_H_

#include <string>
#include <iostream>

class Quote
{
  public:
    Quote() { std::cout << "Quote()" << std::endl; }
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price)
    {
        std::cout << "Quote(const string&, double)" << std::endl;
    }
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price)
    {
        std::cout << "Quote(const Quote&)" << std::endl;
    }
    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
    {
        std::cout << "Quote(Quote&&)" << std::endl;
    }
    Quote &operator=(const Quote &rhs)
    {
        if (this != &rhs)
        {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "operator=(const Quote&)" << std::endl;
        return *this;
    }
    Quote &operator=(Quote &&rhs) noexcept
    {
        if (this != &rhs)
        {
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        std::cout << "operator=(Quote&&)" << std::endl;
        return *this;
    }

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
    {
        return n * price;
    }
    virtual void debug() const;
    virtual ~Quote() = default;

  private:
    std::string bookNo;

  protected:
    double price = 0.0;
};

#endif