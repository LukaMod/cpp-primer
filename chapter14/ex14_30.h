#ifndef EX_14_30_H_
#define EX_14_30_H_

#include <memory>
#include <vector>
#include <string>

#include "ex14_26_StrBlob.h"

class ConstStrBlobPtr
{
  public:
    ConstStrBlobPtr();
    ConstStrBlobPtr(const StrBlob &, size_t sz = 0);

    const std::string &deref() const;
    ConstStrBlobPtr &incr();
    bool unequal(const ConstStrBlobPtr &);
    const std::string &operator*() const;
    const std::string *operator->() const;

  private:
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;

    std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;
};

#endif