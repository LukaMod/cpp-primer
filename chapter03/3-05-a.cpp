#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string largeStr, str;
	while (cin >> str) {
		largeStr += str;
	}
	cout << "The concatenated string: " largeStr << endl;
	return 0;
}