#include "ex13_18.h"

using namespace std;

int Employee::increase = 0;

Employee::Employee()
{
    id = increase++;
}

Employee::Employee(const std::string &n)
{
    name = n;
    id = increase++;
}
