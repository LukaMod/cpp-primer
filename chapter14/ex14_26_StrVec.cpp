#include "ex14_26_StrVec.h"

#include <algorithm>

using namespace std;

allocator<string> StrVec::alloc;

StrVec::StrVec(const StrVec &svec)
{
    auto newdata = alloc_n_copy(svec.begin(), svec.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(initializer_list<string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    elements = data.first;
    first_free = cap = data.second;
}

StrVec &StrVec::operator=(const StrVec &svec)
{
    auto data = alloc_n_copy(svec.begin(), svec.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::StrVec(StrVec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for_each(elements, first_free, [](const string &s) { alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    return lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    auto pl = lhs.begin(), pr = rhs.begin();
    for (; pl != lhs.end() && pr != rhs.end(); ++pl, ++pr)
    {
        if (*pl == *pr)
            ;
        else
            return *pl < *pr;
    }
    return pl == lhs.end() && pr != rhs.end();
}

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
    return !(rhs < lhs);
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
    return rhs < lhs;
}

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs < rhs);
}
