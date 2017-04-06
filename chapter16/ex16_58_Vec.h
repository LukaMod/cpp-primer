#ifndef EX_16_58_VEC_H_
#define EX_16_58_VEC_H_

#include <string>
#include <memory>
#include <initializer_list>
#include <algorithm>
#include <utility>

template <typename T>
class Vec
{
  public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(const Vec &);
    Vec(std::initializer_list<T>);
    Vec &operator=(const Vec &);
    Vec(Vec &&) noexcept;
    Vec &operator=(Vec &&) noexcept;
    ~Vec();

    void push_back(const T &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }
    template <typename... Args>
    void emplace_back(Args &&...);

  private:
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free();
    void reallocate();

    static std::allocator<T> alloc;

    T *elements;
    T *first_free;
    T *cap;
};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
inline Vec<T>::Vec(const Vec &v)
{
    auto newdata = alloc_n_copy(v.begin(), v.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
inline Vec<T>::Vec(std::initializer_list<T> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
inline Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    if (this != &rhs)
    {
        auto data = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
    }
    return *this;
}

template <typename T>
inline Vec<T>::Vec(Vec &&v) noexcept : elements(v.elements), first_free(v.first_free), cap(v.cap)
{
    v.elements = v.first_free = v.cap = nullptr;
}

template <typename T>
inline Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
    }
    return *this;
}

template <typename T>
inline Vec<T>::~Vec()
{
    free();
}

template <typename T>
inline void Vec<T>::push_back(const T &t)
{
    chk_n_alloc();
    alloc.construct(first_free++, t);
}

template <typename T>
inline void Vec<T>::emplace_back(Args &&... args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T>
inline std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
inline void Vec<T>::free()
{
    if (elements)
    {
        std::for_each(elements, first_free, [](const T &t) { alloc.destroy(&t); });
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
inline void Vec<T>::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

#endif