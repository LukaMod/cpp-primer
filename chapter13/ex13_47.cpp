#include "ex13_44.h"

#include <algorithm>
#include <iostream>

std::allocator<char> String::alloc;

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
    std::cout << "String(const String&)" << std::endl;
}

String &String::operator=(const String &rhs)
{
    auto newdata = alloc_n_copy(rhs.elem, rhs.end);
    free();
    elem = newdata.first;
    end = newdata.second;
    std::cout << "operator=(const String&)" << std::endl;
    return *this;
}

String::~String()
{
    free();
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}

void String::free()
{
    if (elem)
    {
        for (auto p = end; p != elem;)
            alloc.destroy(--p);
        alloc.deallocate(elem, end - elem);
    }
}
