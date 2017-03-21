#include "ex14_07.h"

#include <algorithm>
#include <iostream>

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

String::String(String &&s) noexcept : elem(s.elem), end(s.end)
{
    s.elem = s.end = nullptr;
    cout << "String(String&&)" << endl;
}

String &String::operator=(String &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elem = rhs.elem;
        end = rhs.end;
        rhs.elem = rhs.end = nullptr;
    }
    cout << "operator=(String&&)" << endl;
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
        for_each(elem, end, [](const char &c) { alloc.destroy(&c); });
        alloc.deallocate(elem, end - elem);
    }
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    auto p = s.elem;
    while (*p)
        os << *p++;

    return os;
}
