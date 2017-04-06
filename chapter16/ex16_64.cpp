#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
unsigned cnt(const vector<T> &vec, T t)
{
    unsigned ret = 0;
    for (const auto &i : vec)
        if (i == t)
            ++ret;
    return ret;
}

template <>
unsigned cnt(const vector<const char *> &vec, const char *t)
{
    unsigned ret = 0;
    for (const auto &i : vec)
        if (!strcmp(i, t))
            ++ret;
    return ret;
}

int main()
{
    vector<double> dvec{0.7, 0.7, 1.4, 14, 7};
    cout << cnt(dvec, 0.7) << endl;
    vector<string> svec{"hi", "hi", "hi", "hello"};
    cout << cnt(svec, string("hi")) << endl;
    vector<const char *> cvec{"hi", "hi", "hi", "hello"};
    cout << cnt(cvec, "hi") << endl;
    return 0;
}