#include <iostream>

#include "ex15_03.h"

using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " #sold: "
       << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    return 0;
}