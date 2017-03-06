#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

void myReplace(string &s, const string &oldVal, const string &newVal)
{
    for (decltype(s.size()) i = 0; i != s.size(); ++i)
    {
        if (s[i] == oldVal[0] && s.substr(i, oldVal.size()) == oldVal)
        {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size() - 1;
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