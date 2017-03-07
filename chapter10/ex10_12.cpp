#include "../chapter07/ex7_26.h"
#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn().size() < rhs.isbn().size();
}

int main()
{
    Sales_data s1("aa"), s2("a"), s3("bbb"), s4("b"), s5("ab"), s6("ba");
    vector<Sales_data> vec{s1, s2, s3, s4, s5, s6};
    sort(vec.begin(), vec.end(), compareIsbn);
    for (const auto &v : vec)
        print(cout, v) << endl;
    return 0;
}