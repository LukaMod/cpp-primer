#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cin;

int main()
{
	vector<string> vec;
	string str;
	while (cin >> str)
		vec.push_back(str);

	return 0;
}