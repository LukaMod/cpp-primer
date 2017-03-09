#include <list>
#include <string>
#include <iostream>

using namespace std;

void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}

int main()
{
    list<string> ls{"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    elimDups(ls);
    for (const auto &s : ls)
        cout << s << " ";
    cout << endl;
    return 0;
}