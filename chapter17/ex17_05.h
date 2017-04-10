#ifndef EX_17_05_H_
#define EX_17_05_H_

#include <vector>

#include "ex14_02.h"

typedef std::pair<std::vector<Sales_data>::size_type,
                  std::pair<std::vector<Sales_data>::const_iterator,
                            std::vector<Sales_data>::const_iterator>>
    matches_pair;

std::vector<matches_pair> findBook(const std::vector<std::vector<Sales_data>> &, const std::string &);

void reportResults(std::istream &, std::ostream &, const std::vector<std::vector<Sales_data>> &);

#endif