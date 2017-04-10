#ifndef EX_17_04_H_
#define EX_17_04_H_

#include <tuple>
#include <vector>

#include "ex14_02.h"

typedef std::tuple<std::vector<Sales_data>::size_type,
                   std::vector<Sales_data>::const_iterator,
                   std::vector<Sales_data>::const_iterator>
    matches;

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &, const std::string &);

void reportResults(std::istream &, std::ostream &, const std::vector<std::vector<Sales_data>> &);

#endif