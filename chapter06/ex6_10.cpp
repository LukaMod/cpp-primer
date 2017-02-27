#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    cout << "please input two integers: ";
    while (cin >> a >> b)
    {
        swap(&a, &b);
        cout << a << " " << b << endl;
        cout << "please input two integers: ";
    }

    return 0;
}