#ifndef EX_13_26_H_
#define EX_13_26_H_

#include <vector>
#include <memory>

class ConstStrBlobPtr;
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

  public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob &);
    StrBlob &operator=(const StrBlob &);

    size_type size() const;
    bool empty() const;
    void push_back(const std::string &);
    void pop_back();
    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

  private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type i, const std::string &msg) const;
};

#endif