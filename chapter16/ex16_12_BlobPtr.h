#ifndef EX_16_12_BLOBPTR_H_
#define EX_16_12_BLOBPTR_H_

#include "ex16_12_Blob.h"

template <typename>
class BlobPtr;
template <typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator>(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr
{
  public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

    T &operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr &operator++();
    BlobPtr operator++(int);
    BlobPtr &operator--();
    BlobPtr operator--(int);

  private:
    friend bool operator==<T>(const BlobPtr &, const BlobPtr &);
    friend bool operator!=<T>(const BlobPtr &, const BlobPtr &);
    friend bool operator<<T>(const BlobPtr &, const BlobPtr &);
    friend bool operator><T>(const BlobPtr &, const BlobPtr &);

    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;

    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
inline BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(curr, "increment past end of Blob");
    ++curr;
    return *this;
}

template <typename T>
inline BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
inline BlobPtr<T> &BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "decrement past end of Blob");
    return *this;
}

template <typename T>
inline BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template <typename T>
inline std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T>
inline bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw std::runtime_error("ptrs to different Blobs");
    return lhs.curr == rhs.curr;
}

template <typename T>
inline bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
inline bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw std::runtime_error("ptrs to different Blobs");
    return lhs.curr < rhs.curr;
}

template <typename T>
inline bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return rhs > lhs;
}

#endif // !BLOBPTR_H_