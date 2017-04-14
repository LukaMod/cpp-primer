#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    regex r("[^c]ei", regex::icase);
    string s;
    while (cin >> s)
    {
        if (!regex_match(s, r))
            cout << s << endl;
    }

    return 0;
}