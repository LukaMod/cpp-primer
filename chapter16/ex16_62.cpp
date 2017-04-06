#include <iostream>
#include <unordered_set>

#include "ex16_62_Sales_data.h"

using namespace std;

int main()
{
    unordered_multiset<Sales_data> mset;
    Sales_data item("xyx", 14, 0.7);
    mset.emplace(item);
    mset.emplace("luka", 5, 0.25);
    for (const auto &i : mset)
        cout << "the hash code of " << i.isbn() << ":\n"
             << hash<Sales_data>()(i) << endl;
    return 0;
}