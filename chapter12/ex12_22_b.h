#ifndef EX_12_22_B_H_
#define EX_12_22_B_H_

#include <memory>
#include <vector>
#include <string>

#include "StrBlob.h"

class ConstStrBlobPtr
{
public:
  ConstStrBlobPtr();
  ConstStrBlobPtr(const StrBlob &, size_t sz = 0);

  const std::string &deref() const;
  ConstStrBlobPtr &incr();
  bool unequal(const ConstStrBlobPtr &);

private:
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;

  std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;
};

#endif