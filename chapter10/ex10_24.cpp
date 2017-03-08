#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

int main()
{
    vector<int> vec{1, 2, 3, 8, 7, 9};
    string str("hello");
    auto i = find_if(vec.cbegin(), vec.cend(), bind(check_size, str, _1));
    cout << *i << endl;
    return 0;
}