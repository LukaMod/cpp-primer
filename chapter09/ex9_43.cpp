#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

void myReplace(string &s, const string &oldVal, const string &newVal)
{
    for (auto &iter = s.cbegin(); iter != s.cend(); ++iter)
    {
        if (*iter == oldVal.front() && s.cend() - iter >= oldVal.cend() - oldVal.cbegin())
        {
            if (string(iter, iter + oldVal.size()) == oldVal)
            {
                auto distance = iter - s.cbegin();
                s.erase(iter, iter + oldVal.size());
                s.insert(iter, newVal.cbegin(), newVal.cend());
                iter = s.cbegin() + distance + newVal.size() - 1;
            }
        }
    }
}

int main()
{
    {
        string str{"To drive straight thru is a foolish, tho courageous act."};
        myReplace(str, "thru", "through");
        myReplace(str, "tho", "though");
        cout << str << endl;
    }
    {
        string str{"To drive straight thruthru is a foolish, thotho courageous act."};
        myReplace(str, "thru", "through");
        myReplace(str, "tho", "though");
        cout << str << endl;
    }
    {
        string str{"To drive straight thru is a foolish, tho courageous act."};
        myReplace(str, "thru", "through");
        myReplace(str, "tho", "though");
        cout << str << endl;
    }
    {
        string str{"my world is a big world"};
        myReplace(str, "world", "worldddddddddddddd");
        cout << str << endl;
    }

    return 0;
}