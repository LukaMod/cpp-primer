#include "ex14_30.h"

#include "ex14_26_StrBlob.h"

using namespace std;

ConstStrBlobPtr::ConstStrBlobPtr() : curr(0) {}

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {}

const string &ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

bool ConstStrBlobPtr::unequal(const ConstStrBlobPtr &rhs)
{
    return curr != rhs.curr;
}

const std::string &ConstStrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

const std::string *ConstStrBlobPtr::operator->() const
{
    return &this->operator*();
}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound ConstBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
