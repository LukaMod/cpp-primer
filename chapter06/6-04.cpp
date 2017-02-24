#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

int main()
{
    int val;
    cout << "please input a natural number: ";
    while (cin >> val)
    {
        cout << val << "! is " << fact(val) << endl;
        cout << "please input a natural number: ";
    }

    return 0;
}