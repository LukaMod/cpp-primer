#include "ex14_26_StrBlobPtr.h"

#include <string>
#include <vector>
#include <exception>

#include "ex14_26_StrBlob.h"

StrBlobPtr::StrBlobPtr() : curr(0) {}

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {}

std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline std::string &StrBlobPtr::operator[](std::size_t n)
{
    auto p = check(n, "dereference out of range");
    return (*p)[n];
}

inline const std::string &StrBlobPtr::operator[](std::size_t n) const
{
    auto p = check(n, "dereference out of range");
    return (*p)[n];
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.curr < rhs.curr;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(rhs < lhs);
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return rhs < lhs;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs < rhs);
}
