#include "ex17_06.h"

#include <algorithm>
#include <numeric>

using namespace std;

vector<matches_struct> findBook(const vector<vector<Sales_data>> &files, const string &book)
{
    vector<matches_struct> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = equal_range(it->cbegin(), it->cend(), book,
                                 [](const Sales_data &lhs, const Sales_data &rhs) { return lhs.isbn() < rhs.isbn(); });
        if (found.first != found.second)
            ret.push_back(matches_struct(it - files.cbegin(), found.first, found.second));
    }
    return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
    string s;
    while (in >> s)
    {
        auto trans = findBook(files, s);
        if (trans.empty())
        {
            cout << s << " not found in any stores" << endl;
            continue;
        }
        for (const auto &store : trans)
            os << "store " << store.index << " sales: "
               << accumulate(store.first, store.last, Sales_data(s))
               << endl;
    }
}