#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

string pre_suffix(const string &s, const string &pre, const string &suffix)
{
    string ret = s;
    ret.insert(ret.cbegin(), pre.cbegin(), pre.cend());
    ret.append(suffix);
    return ret;
}

int main()
{
    cout << pre_suffix("Luka", "Mr.", "III") << endl;
    return 0;
}