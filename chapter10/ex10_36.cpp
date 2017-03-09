#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    list<int> ls{3, 4, 6, 2, 0, 1, 3, 7, 0, 4};
    auto it = find(ls.crbegin(), ls.crend(), 0);
    cout << *it << endl;
    return 0;
}