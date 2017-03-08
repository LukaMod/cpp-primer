#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool isShorter(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

int main()
{
    vector<string> vec{"hello mike", "hehe what", "ah", "bitch fuck", "hehe", "haha", "ha", "ia"};
    auto cnt = count_if(vec.cbegin(), vec.cend(),
                        bind(isShorter, _1, 6));
    cout << cnt << endl;
    return 0;
}