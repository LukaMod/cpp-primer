#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;
using std::count;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec;
    int i;
    while (cin >> i)
        vec.push_back(i);
    cout << count(vec.cbegin(), vec.cend(), 9) << endl;

    return 0;
}