#ifndef EX_12_19_B_H_
#define EX_12_19_B_H_

#include <string>
#include <vector>
#include <memory>

#include "ex12_19_a.h"

using std::vector;
using std::string;
using std::shared_ptr;
using std::initializer_list;

class StrBlob
{
    friend class StrBlobPtr;

  public:
    typedef vector<string>::size_type size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end()
    {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }

  private:
    shared_ptr<vector<string>> data;

    void check(size_type i, const string &msg) const;
};

#endif