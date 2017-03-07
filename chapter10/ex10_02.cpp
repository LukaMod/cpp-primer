#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using std::string;
using std::list;
using std::count;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    list<string> lst;
    string s;
    while (cin >> s)
        lst.push_back(s);
    cout << count(lst.cbegin(), lst.cend(), "he") << endl;
    return 0;
}