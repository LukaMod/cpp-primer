#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    int ia[10];
    int *beg = begin(ia);
    int *last = end(ia);
    for (; beg != last; ++beg)
        *beg = 0;
    for (auto i : ia)
        cout << i << " ";
    cout << endl;
    return 0;
}