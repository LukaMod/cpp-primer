#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string str;
    cout << "Enter a string including punctuations:" << endl;
    getline(cin, str);
    for (auto c : str)
    {
	if (!ispunct(c))
	    cout << c;
    }
    cout << endl;
    return 0;
}