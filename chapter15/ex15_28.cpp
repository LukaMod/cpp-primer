#include <vector>

#include "ex15_15_Bulk_quote.h"

using namespace std;

int main()
{
    vector<Quote> basket;
    for (auto i = 0; i != 14; ++i)
        basket.push_back(Bulk_quote("x-y-x", 14, 7, 0.14));
    double total = 0;
    for (const auto &v : basket)
        total += v.net_price(10);
    cout << total << endl;
    return 0;
}