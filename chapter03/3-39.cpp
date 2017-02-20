#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	const char ca[] = { 'h', 'e', 'l', 'l', 'o', 0 };
	const char *cp = ca;
	cout << strcmp(ca, cp) << endl;
	string str1 = "haha";
	string str2 = "he";
	cout << (str1 < str2) << endl;

	return 0;
}