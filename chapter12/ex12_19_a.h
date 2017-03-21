#ifndef EX_12_19_A_H_
#define EX_12_19_A_H_

#include <string>
#include <vector>
#include <memory>

class StrBlob;

class StrBlobPtr
{
public:
  StrBlobPtr();
  StrBlobPtr(StrBlob &, size_t sz = 0);

  std::string &deref() const;
  StrBlobPtr &incr();
  bool unequal(const StrBlobPtr &);

private:
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;

  std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;
};

#endif
