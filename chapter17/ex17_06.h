#ifndef EX_17_06_H_
#define EX_17_06_H_

#include <vector>

#include "ex14_02.h"

struct matches_struct
{
    matches_struct(std::vector<Sales_data>::size_type sz,
                   std::vector<Sales_data>::const_iterator f,
                   std::vector<Sales_data>::const_iterator l) : index(sz), first(f), last(l) {}

    std::vector<Sales_data>::size_type index;
    std::vector<Sales_data>::const_iterator first;
    std::vector<Sales_data>::const_iterator last;
};

std::vector<matches_struct> findBook(const std::vector<std::vector<Sales_data>> &, const std::string &);

void reportResults(std::istream &, std::ostream &, const std::vector<std::vector<Sales_data>> &);

#endif