#include "ex14_26_StrBlob.h"

#include "ex14_26_StrBlobPtr.h"
#include "ex12_22_b.h"

using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

StrBlob::StrBlob(const StrBlob &rhs) : data(make_shared<vector<string>>(*rhs.data)) {}

StrBlob &StrBlob::operator=(const StrBlob &rhs)
{
    data = make_shared<vector<string>>(*rhs.data);
    return *this;
}

StrBlob::size_type StrBlob::size() const
{
    return data->size();
}

bool StrBlob::empty() const
{
    return data->empty();
}

void StrBlob::push_back(const string &t)
{
    data->push_back(t);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}

std::string &StrBlob::operator[](std::size_t n)
{
    check(n, "out of range");
    return data->at(n);
}

const std::string &StrBlob::operator[](std::size_t n) const
{
    check(n, "out of range");
    return data->at(n);
}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(rhs < lhs);
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return rhs < lhs;
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs < rhs);
}
