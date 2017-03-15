#ifndef EX_12_19_A_H_
#define EX_12_19_A_H_

#include <string>
#include <vector>
#include <memory>

#include "ex12_19_b.h"

using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::vector;

class StrBlobPtr
{
public:
  StrBlobPtr();
  StrBlobPtr(StrBlob &, size_t sz = 0);

  string &deref() const;
  StrBlobPtr &incr();
  bool unequal(const StrBlobPtr &);

private:
  weak_ptr<vector<string>> wptr;
  size_t curr;

  shared_ptr<vector<string>> check(size_t, const string &) const;
};

#endif
