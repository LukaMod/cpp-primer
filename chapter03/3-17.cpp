#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<string> vec;
    string str;
    while (cin >> str)
	vec.push_back(str);
    for (auto &s : vec)
    {
	for (auto &c : s)
	    c = toupper(c);
    }
    for (auto s : vec)
	cout << s << endl;
    return 0;
}