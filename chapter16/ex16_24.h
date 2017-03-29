#ifndef EX_16_24_H_
#define EX_16_24_H_

#include <vector>
#include <memory>
#include <string>

template <typename>
class BlobPtr;
template <typename>
class Blob;
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator!=(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob
{
  public:
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T>);
    template <typename It>
    Blob(It, It);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void pop_back();
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    T &operator[](size_type i);
    const T &operator[](size_type i) const;

  private:
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob &, const Blob &);
    friend bool operator!=<T>(const Blob &, const Blob &);

    void check(size_type, const std::string &) const;

    std::shared_ptr<std::vector<T>> data;
};

template <typename T>
inline Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
inline Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
template <typename It>
inline Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}

template <typename T>
inline void Blob<T>::pop_back()
{
    check(0, "back on empty Blob");
    data->pop_back();
}

template <typename T>
inline T &Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
inline const T &Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
inline T &Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
inline const T &Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
inline T &Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
inline const T &Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
inline bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data == *rhs.data;
}

template <typename T>
inline bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs == rhs);
}

#endif // !BLOB_H_