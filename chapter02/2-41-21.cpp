#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data data1, data2;
    double price1, price2;
    std::cin >> data1.bookNo >> data1.units_sold >> price1;
    std::cin >> data2.bookNo >> data2.units_sold >> price2;
    data1.revenue = data1.units_sold * price1;
    data2.revenue = data2.units_sold * price2;
    if (data1.bookNo == data2.bookNo)
    {
        unsigned units_sold = data1.units_sold + data2.units_sold;
        double revenue = data1.revenue + data2.revenue;
        std::cout << data1.bookNo << " " << units_sold << " " << revenue << " ";
        if (units_sold)
            std::cout << revenue / units_sold << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }

    return 0;
}