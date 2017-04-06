#ifndef EX_16_62_SALES_DATA_H_
#define EX_16_62_SALES_DATA_H_

#include <iostream>
#include <string>

class Sales_data
{
    friend class std::hash<Sales_data>;

    friend bool operator==(const Sales_data &, const Sales_data &);
    friend bool operator!=(const Sales_data &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend std::istream &operator>>(std::istream &, Sales_data &);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);

  public:
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data() : Sales_data("", 0, 0.0) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {}
    Sales_data(std::istream &is) : Sales_data()
    {
        is >> *this;
    }

    explicit operator std::string() const { return bookNo; }
    explicit operator double() const { return avg_price(); }
    Sales_data &operator+=(const Sales_data &);
    Sales_data &operator=(const std::string &);
    std::string isbn() const { return bookNo; }

  private:
    double avg_price() const { return units_sold ? revenue / units_sold : 0; }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

namespace std
{

template <>
struct hash<Sales_data>
{
    typedef size_t result_type;
    typedef Sales_data argument_type;
    size_t operator()(const Sales_data &s) const
    {
        return hash<std::string>()(s.bookNo) ^
               hash<unsigned>()(s.units_sold) ^
               hash<double>()(s.revenue);
    }
};

} // namespace std

#endif