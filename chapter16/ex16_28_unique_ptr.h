#ifndef UNIQUE_POINTER_H_
#define UNIQUE_POINTER_H_

#include <memory>

template <typename>
class unique_pointer;
template <typename T, typename D>
void swap(unique_pointer<T, > &, unique_pointer<T, > &);

template <typename T, typename D = std::default_delete<T>>
class unique_pointer
{
  public:
    unique_pointer() = default;
    unique_pointer<T, D>(const D &d) : del(d) {}
    unique_pointer(T *q) : p(q) {}
    unique_pointer<T, D>(T *q, const D &d) : p(q), del(d) {}

    unique_pointer(const unique_pointer &) = delete;
    unique_pointer(unique_pointer &&up) noexcept : p(up.p), del(up.del) { up.p = nullptr; }
    unique_pointer &operator=(const unique_pointer &) = delete;
    unique_pointer &operator=(unique_pointer &&) noexcept;
    ~unique_pointer() { del(p); }

    operator bool() const { return p ? true : false; }
    T &operator*() const { return *p; }
    T *operator->() const { return p; }
    T *get() const { return p; }
    void swap(unique_pointer &rhs) { ::swap(*this, rhs); }
    T *release();
    void reset()
    {
        del(p);
        p = nullptr;
    }
    void reset(T *q)
    {
        del(p);
        p = q;
    }

  private:
    friend void swap(unique_pointer &, unique_pointer &);

    T *p = nullptr;
    D del;
};

template <typename T, typename D>
inline unique_pointer<T, > &unique_pointer<T, >::operator=(unique_pointer &&rhs) noexcept
{
    del(p);
    p = rhs.p;
    del = rhs.del;
    rhs.p = nullptr;
    return *this;
}

template <typename T, typename D>
inline T *unique_pointer<T, >::release()
{
    T *ret = p;
    del(p);
    return ret;
}

template <typename T, typename D>
inline void swap(unique_pointer<T, > &lhs, unique_pointer<T, > &rhs)
{
    using std::swap;
    swap(lhs.p, rhs.p);
    swap(lhs.del, rhs.del);
}

#endif // !UNIQUE_POINTER_H_
