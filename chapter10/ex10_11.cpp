#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::unique;
using std::stable_sort;
using std::vector;

void printStr(const vector<string> &v)
{
    for (const auto &s : v)
        cout << s << " ";
    cout << endl;
}

inline bool isShorter(const string &lhs, const string &rhs)
{
    return lhs.size() < rhs.size();
}

void elimDups(vector<string> &v)
{
    sort(v.begin(), v.end());
    auto end_unique = unique(v.begin(), v.end());
    printStr(v);
    v.erase(end_unique, v.end());
}

int main()
{
    vector<string> vec;
    string str;
    while (cin >> str)
        vec.push_back(str);
    elimDups(vec);
    printStr(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    printStr(vec);
    return 0;
}