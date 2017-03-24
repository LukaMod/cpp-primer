#include "ex15_30_Bulk_quote.h"
#include "ex15_30_Basket.h"

using namespace std;

int main()
{
    Basket basket;
    for (auto i = 0; i != 14; ++i)
        basket.add_item(Bulk_quote("x-y-x", 14, 7, 0.14));
    for (auto i = 0; i != 7; ++i)
        basket.add_item(Bulk_quote("1-2-1", 7, 93, 0.5));
    basket.total_receipt(cout);
    return 0;
}