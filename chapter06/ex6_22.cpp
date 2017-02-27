#include <iostream>

using std::cout;
using std::endl;

void swapPtr(int *&p1, int *&p2)
{
    int *temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    int a = 7, b = 14;
    int *pa = &a, *pb = &b;
    swapPtr(pa, pb);
    cout << "*pa = " << *pa << "\n"
         << "*pb = " << *pb << endl;
    return 0;
}