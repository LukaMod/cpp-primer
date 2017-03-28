#include <iostream>
#include <vector>

using namespace std;

template <typename iterT, typename valT>
iterT tfind(const iterT &beg, const iterT &end, const valT &v)
{
    auto iter = beg;
    while (iter != end && *iter != v)
        ++iter;
    return iter;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    auto it = tfind(vec.cbegin(), vec.cend(), 7);
    cout << *it << endl;
    return 0;
}