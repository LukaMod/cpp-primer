#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> ls;
    copy(vec.crbegin() + 3, vec.crbegin() + 7, back_inserter(ls));
    for (const auto &i : ls)
        cout << i << " ";
    cout << endl;
    return 0;
}