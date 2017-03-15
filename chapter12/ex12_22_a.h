#ifndef EX_12_22_A_H_
#define EX_12_22_A_H_

#include <vector>
#include <memory>

using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;

class StrBlob
{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

  public:
    typedef vector<string>::size_type size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);

    size_type size() const;
    bool empty() const;
    void push_back(const string &);
    void pop_back();
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

  private:
    shared_ptr<vector<string>> data;

    void check(size_type i, const string &msg) const;
};

#endif