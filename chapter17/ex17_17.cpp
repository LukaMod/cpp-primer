#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);
    string s;
    getline(cin, s);
    for (sregex_iterator it(s.cbegin(), s.cend(), r), end_it; it != end_it; ++it)
        cout << it->str() << endl;

    return 0;
}