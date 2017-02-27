#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    cout << isShorter("haha", "he") << endl;

    return 0;
}