#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename C>
void print(const C &c)
{
    for (auto iter = c.cbegin(); iter != c.cend(); ++iter)
        cout << *iter << " ";
}

int main()
{
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};
    print(vec);
    cout << endl;
    unordered_set<int> uset{1, 2, 3, 4, 5, 6, 7};
    print(uset);
    cout << endl;
    return 0;
}