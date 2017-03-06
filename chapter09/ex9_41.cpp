#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<char> vec{'x', 'y', 'x', '7', '1', '4'};
    string s(vec.cbegin(), vec.cend());
    cout << s << endl;
    return 0;
}