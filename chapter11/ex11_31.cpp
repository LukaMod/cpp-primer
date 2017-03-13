#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    multimap<string, string> authors{
        {"xyx", "flower"}, {"xyx", "tang"}, {"luka", "g"}, {"xyx", "sheep"}, {"uncle", "mine"}, {"xyx", "sheep"}};
    string author{"xyx"};
    string work{"sheep"};

    auto count = authors.count(author);
    auto found = authors.find(author);
    while (count)
    {
        if (found->second == work)
        {
            found = authors.erase(found);
        }
        else
            ++found;
        --count;
    }
    for (const auto &au : authors)
        cout << au.first << " " << au.second << endl;
    return 0;
}
