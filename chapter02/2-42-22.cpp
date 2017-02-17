#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data total;
	double totalPrice;
	if (std::cin >> total.bookNo >> total.units_sold >> totalPrice) {
		total.revenue = total.units_sold * totalPrice;
		
		Sales_data trans;
		double transPrice;
		while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice) {
			trans.revenue = trans.units_sold * transPrice;
			if (trans.bookNo == total.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				std::cout << total.bookNo << " " << total.units_sold << " "
					<< total.revenue << " ";
				if (total.units_sold)
					std::cout << total.revenue / total.units_sold << std::endl;
				else
					std::cout << "(no sales)" << std::endl;
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		std::cout << total.bookNo << " " << total.units_sold << " "
			<< total.revenue << " ";
		if (total.units_sold)
			std::cout << total.revenue / total.units_sold << std::endl;
		else
			std::cout << "(no sales)" << std::endl;
	}
	else {
		std::cout << "No data?!" << std::endl;
		return -1;
	}
	
	return 0;
}