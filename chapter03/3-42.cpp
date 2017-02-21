#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    int a[7];
    for (int *p = begin(a); p != end(a); ++p)
        *p = vec[p - begin(a)];
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}