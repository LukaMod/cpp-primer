#include "ex13_44.h"

#include <algorithm>

using namespace std;

allocator<char> String::alloc;

String::String(const char *s)
{
    auto p = s;
    while (*p)
        ++p;
    auto str = alloc_n_copy(s, ++p);
    elem = str.first;
    end = str.second;
}

String::String(const String &s)
{
    auto str = alloc_n_copy(s.elem, s.end);
    elem = str.first;
    end = str.second;
}

String &String::operator=(const String &rhs)
{
    auto newdata = alloc_n_copy(rhs.elem, rhs.end);
    free();
    elem = newdata.first;
    end = newdata.second;
    return *this;
}

String::~String()
{
    free();
}

pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return {str, uninitialized_copy(b, e, str)};
}

void String::free()
{
    if (elem)
    {
        for_each(elem, end, [](const char &c) { alloc.destroy(c); });
        alloc.deallocate(elem, end - elem);
    }
}
