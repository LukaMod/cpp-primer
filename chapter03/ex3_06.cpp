#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string str("An sample string");
    for (auto &c : str)
        c = 'X';
    cout << str << endl;
    return 0;
}