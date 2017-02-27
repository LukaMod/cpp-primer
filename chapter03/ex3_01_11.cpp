#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int v1 = 0, v2 = 0;
    cout << "Enter two numbers:" << endl;
    cin >> v1 >> v2;
    if (v1 > v2)
    {
        int temp;
        temp = v1;
        v1 = v2;
        v2 = temp;
    }
    cout << "Numbers between " << v1 << " and " << v2 << " are :" << endl;
    while (v1 <= v2)
    {
        cout << v1 << " ";
        ++v1;
    }
    cout << endl;
    return 0;
}