#ifndef EX_14_26_STRBLOBPTR_H_
#define EX_14_26_STRBLOBPTR_H_

#include <string>
#include <vector>
#include <memory>

class StrBlob;

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

  public:
    StrBlobPtr();
    StrBlobPtr(StrBlob &, size_t sz = 0);

    std::string &deref() const;
    StrBlobPtr &incr();
    std::string &operator[](std::size_t);
    const std::string &operator[](std::size_t) const;

  private:
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;

    std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;
};

#endif
