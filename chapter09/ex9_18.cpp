#include <iostream>
#include <string>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;

int main()
{
    string str;
    deque<string> dq;
    while (cin >> str)
        dq.push_back(str);
    for (auto &iter = dq.cbegin(); iter != dq.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;
    return 0;
}