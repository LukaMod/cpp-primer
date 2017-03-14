#include "ex12_02.h"

using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

inline void StrBlob::pop_back()
{
    check(0, "back on empty StrBlob");
    data->pop_back();
}

inline string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}