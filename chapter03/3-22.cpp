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
    vector<string> text;
    string line;
    while (getline(cin, line))
	text.push_back(line);
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
	for (auto &c : *it)
	    c = toupper(c);
	cout << *it;
    }

    return 0;
}