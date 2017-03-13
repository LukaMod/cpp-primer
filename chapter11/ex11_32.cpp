#include <map>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    multimap<string, string> authors{
        {"xyx", "flower"}, {"xyx", "tang"}, {"luka", "g"}, {"xyx", "sheep"}, {"uncle", "mine"}, {"xyx", "sheep"}};
    map<string, set<string>> works;
    for (const auto &au : authors)
    {
        if (works.count(au.first))
            works[au.first].insert(au.second);
        else
            works.insert({au.first, {au.second}});
    }
    for (const auto &w : works)
    {
        cout << w.first << " : ";
        for (const auto &wsecond : w.second)
            cout << wsecond << " ";
        cout << endl;
    }

    return 0;
}
