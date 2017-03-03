#include <iostream>
#include <string>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

int main()
{
    string str;
    list<string> ls;
    while (cin >> str)
        ls.push_back(str);
    for (auto &iter = ls.cbegin(); iter != ls.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;
    return 0;
}