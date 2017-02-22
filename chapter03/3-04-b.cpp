#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.size() == str2.size())
	cout << "Equal length: " << str1 << endl;
    else
	cout << "The longer: " << (str1.size() > str2.size() ? str1 : str2) << endl;

    return 0;
}