#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};