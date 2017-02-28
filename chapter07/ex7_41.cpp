#include <iostream>
#include "ex7_41.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "1. default: " << endl;
    Sales_data s1;
    cout << "\n2. string: " << endl;
    Sales_data s2("cpp");
    cout << "\n3. string, unsigned, double: " << endl;
    Sales_data s3("cpp", 7, 14.0);
    cout << "\n4. istream: " << endl;
    Sales_data s4(cin);

    return 0;
}