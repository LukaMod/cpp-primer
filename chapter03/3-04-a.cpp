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
	if (str1 == str2)
		cout << "Equal: " << str1 << endl;
	else
		cout << "The larger: " << (str1 > str2 ? str1 : str2) << endl;
	
	return 0;
}