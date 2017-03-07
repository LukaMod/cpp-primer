#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::unique;
using std::vector;

void elimDups(vector<int> &v)
{
    sort(v.begin(), v.end());
    auto end_unique = unique(v.begin(), v.end());
    for (const auto &i : v)
        cout << i << " ";
    cout << endl;
    v.erase(end_unique, v.end());
}

int main()
{
    vector<int> vec;
    int i;
    while (cin >> i)
        vec.push_back(i);
    for (const auto &i : vec)
        cout << i << " ";
    cout << endl;
    elimDups(vec);
    for (const auto &i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}