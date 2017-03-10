#include <string>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<pair<string, int>> vec;
    string s;
    int i;
    while (cin >> s >> i)
        vec.push_back({s, i});
    for (const auto &v : vec)
        cout << v.first << " : " << v.second << endl;
    return 0;
}