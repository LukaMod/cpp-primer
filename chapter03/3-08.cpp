#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string str("An sample string");
    decltype(str.size()) i = 0;

    while (i != str.size())
    {
        str[i] = 'X';
        ++i;
    }
    cout << str << endl;

    for (i = 0; i != str.size(); ++i)
        str[i] = 'Y';
    cout << str << endl;

    return 0;
}