#include <iostream>
#include <list>
#include <deque>
using std::cout;
using std::endl;
using std::list;
using std::deque;

int main()
{
    list<int> ls{0, 1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> odd, even;
    for (const auto &i : ls)
        (i & 0x1 ? odd : even).push_back(i);
    for (const auto &v : odd)
        cout << v << " ";
    cout << endl;
    for (const auto &v : even)
        cout << v << " ";
    cout << endl;

    return 0;
}