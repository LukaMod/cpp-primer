#include <iostream>
#include "ex7_12.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main()
{
    Sales_data total(cin);
    if (!total.isbn().empty())
    {
        while (cin)
        {
            Sales_data trans(cin);
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
        return -1;
    }

    return 0;
}
