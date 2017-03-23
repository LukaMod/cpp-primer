#include <iostream>

#include "ex15_03.h"
#include "ex15_05.h"

using namespace std;

double print_total(ostream &, const Quote &, size_t);

int main()
{
    Quote q("x-y-x", 7.14);
    Bulk_quote bq("x-y-x", 7.14, 10, 0.3);
    print_total(cout, q, 14);
    print_total(cout, bq, 14);
    return 0;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " #sold: "
       << n << " total due: " << ret << endl;
    return ret;
}
