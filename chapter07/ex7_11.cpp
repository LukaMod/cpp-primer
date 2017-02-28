#include <iostream>
#include "ex7_11.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    Sales_data item1;
    print(cout, item1) << endl;

    Sales_data item2("1993-07-14-xyx");
    print(cout, item2) << endl;

    Sales_data item3("1993-07-14-xyx", 1, 666);
    print(cout, item3) << endl;

    Sales_data item4(cin);
    print(cout, item4) << endl;

    return 0;
}