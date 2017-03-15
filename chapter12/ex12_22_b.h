#ifndef EX_12_22_B_H_
#define EX_12_22_B_H_

#include <memory>
#include <vector>
#include <string>

#include "ex12_22_a.h"

using std::string;
using std::vector;
using std::weak_ptr;

class ConstStrBlobPtr
{
  public:
    ConstStrBlobPtr();
    ConstStrBlobPtr(const StrBlob &, size_t sz = 0);

    const string &deref() const;
    ConstStrBlobPtr &incr();
    bool unequal(const ConstStrBlobPtr &);

  private:
    weak_ptr<vector<string>> wptr;
    size_t curr;

    shared_ptr<vector<string>> check(size_t, const string &) const;
};

#endif