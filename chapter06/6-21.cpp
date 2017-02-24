#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int toLarger(const int a, const int *b)
{
    return a > *b ? a : *b;
}

int main()
{
    int i = 7;
    cout << toLarger(14, &i) << endl;
    return 0;
}