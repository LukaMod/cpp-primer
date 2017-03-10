#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    multimap<string, string> family;
    string lastName, childName;
    while (cin >> lastName >> childName)
    {
        family.insert({lastName, childName});
    }
    for (const auto &f : family)
        cout << f.first << " " << f.second << endl;

    return 0;
}