#include <iostream>

using std::cout;
using std::endl;

void reset(int &i)
{
    i = 0;
}

int main()
{
    int j = 7;
    reset(j);
    cout << "j = " << j << endl;
    return 0;
}