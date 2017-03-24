#ifndef EX_15_30_BASKET_H_
#define EX_15_30_BASKET_H_

#include <memory>
#include <set>

#include "ex15_30_Bulk_quote.h"

class Basket
{
  public:
    void add_item(const Quote &sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale)
    {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(std::ostream &) const;

  private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }

    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

#endif // !BASKET_H_
