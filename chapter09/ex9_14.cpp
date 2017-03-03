#include <list>
#include <vector>
#include <iostream>
#include <string>
using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::string;

int main()
{
    list<char *> li{"haha", "hehe", "kkk"};
    vector<string> vec;
    vec.assign(li.cbegin(), li.cend());
    for (const auto &s : vec)
        cout << s << " ";
    cout << endl;
    return 0;
}