#include <iostream>
#include <string>

using namespace std;

template <typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args &... rest)
{
    os << t << ",";
    return print(os, rest...);
}

int main()
{
    print(cout, 7);
    print(cout, 7, "M");
    print(cout, 1993, 07, "M", 14);
    return 0;
}