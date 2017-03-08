#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::count_if;

int main()
{
    vector<string> vec{"hello mike", "hehe what", "ah", "bitch fuck", "hehe", "haha", "ha", "ia"};
    auto cnt = count_if(vec.cbegin(), vec.cend(),
                        [](const string &s) { return s.size() > 6; });
    cout << cnt << endl;
    return 0;
}