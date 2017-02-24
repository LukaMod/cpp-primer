#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

bool hasUpper(const string &str)
{
    for (auto &c : str)
        if (isupper(c))
            return true;
    return false;
}

void toLower(string &str)
{
    for (auto &c : str)
        c = tolower(c);
}

int main()
{
    string s("Hello, World!");
    cout << hasUpper(s) << " " << s << endl;
    toLower(s);
    cout << hasUpper(s) << " " << s << endl;
    return 0;
}