#include "ex16_65.h"

using namespace std;

string debug_rep(const string &s)
{
    return '"' + s + '"';
}

template <>
string debug_rep(char *p)
{
    return debug_rep(string(p));
}

template <>
string debug_rep(const char *p)
{
    return debug_rep(string(p));
}