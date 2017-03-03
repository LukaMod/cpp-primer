#include "../chapter07/ex7_41.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;

int main(int argc, char *argv[])
{
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(output, total);
                total = trans;
            }
        }
        print(output, total);
    }
    else
        cerr << "No data?!" << endl;
    return 0;
}