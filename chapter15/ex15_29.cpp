#include <memory>
#include <vector>

#include "ex15_15_Bulk_quote.h"

using namespace std;

int main()
{
    vector<shared_ptr<Quote>> basket;
    for (auto i = 0; i != 14; ++i)
        basket.push_back(make_shared<Bulk_quote>("x-y-x", 14, 7, 0.14));
    double total = 0;
    for (const auto &v : basket)
        total += v->net_price(10);
    cout << total << endl;
    return 0;
}