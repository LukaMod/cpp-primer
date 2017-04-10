#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    bitset<32> b1, b2;
    int a[]{1, 2, 3, 5, 8, 13, 21};
    for (auto i : a)
        b1.set(i);
    for (auto i = 0; i != b1.size(); ++i)
        b2[i] = ~b1[i];
    cout << b1 << endl;
    cout << b2 << endl;
    return 0;
}