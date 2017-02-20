#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data data;
    double price;
    while (std::cin >> data.bookNo >> data.units_sold >> price)
    {
	data.revenue = data.units_sold * price;
	std::cout << data.bookNo << " " << data.units_sold << " "
		  << data.revenue << " " << price << std::endl;
    }
    return 0;
}