#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int v = 10;
    while (v >= 0)
    {
	cout << v << endl;
	--v;
    }
    return 0;
}