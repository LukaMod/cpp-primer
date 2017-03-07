#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::partition;

inline bool wordFilter(const string &s)
{
    return s.size() >= 5;
}

int main()
{
    vector<string> vec;
    string word;
    while (cin >> word)
        vec.push_back(word);
    auto iter = partition(vec.begin(), vec.end(), wordFilter);
    for (auto it = vec.cbegin(); it != iter; ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}