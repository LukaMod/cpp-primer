#ifndef EX_16_28_SHARED_POINTER_H_
#define EX_16_28_SHARED_POINTER_H_

#include <functional>

template <typename>
class shared_pointer;

template <typename T, typename... Args>
shared_pointer<T> make_sharedptr(Args &&...);

template <typename T>
void swap(shared_pointer<T> &, shared_pointer<T> &);

template <typename T>
class shared_pointer
{
  public:
    shared_pointer() : p(nullptr) {}
    explicit shared_pointer(T *ptr, std::function<void(T *)> d = nullptr) : p(ptr), count(new std::size_t(1)), del(d) {}

    shared_pointer(const shared_pointer &sp) : p(sp.p), count(sp.count) { ++*sp.count; }
    shared_pointer(const shared_pointer &sp, std::function<void(T *)> d) : p(sp.p), count(sp.count), del(d) { ++*sp.count; }
    shared_pointer(shared_pointer &&sp) noexcept : p(sp.p), count(sp.count), del(std::move(sp.del))
    {
        sp.p = nullptr;
        sp.count = nullptr;
    }
    shared_pointer &operator=(shared_pointer);

    operator bool() const { return p ? true : false; }
    T &operator*() const { return *p; }
    T *operator->() const { return p; }
    T *get() const noexcept { return p; }
    std::size_t use_count() const { return *count; }
    bool unique() const { return use_count == 1; }
    void swap(shared_pointer &rhs) { ::swap(*this, rhs); }
    void reset() noexcept;
    void reset(T *);
    void reset(T *, const std::function<void(T *)> &);

  private:
    friend void swap(shared_pointer &, shared_pointer &);

    void destroy();

    T *p;
    std::size_t *count = new std::size_t(0);
    std::function<void(T *)> del = nullptr;
};

template <typename T>
inline shared_pointer<T> &shared_pointer<T>::operator=(shared_pointer rhs)
{
    swap(*this, rhs);
    return *this;
}

template <typename T>
inline void shared_pointer<T>::reset() noexcept
{
    destroy();
}

template <typename T>
inline void shared_pointer<T>::reset(T *q)
{
    if (p != q)
    {
        destroy();
        p = q;
        count = new std::size_t(1);
    }
}

template <typename T>
inline void shared_pointer<T>::reset(T *q, const std::function<void(T *)> &d)
{
    reset(q);
    del = d;
}

template <typename T>
inline void shared_pointer<T>::destroy()
{
    if (p)
    {
        if (--*count == 0)
        {
            del ? del(p) : delete p;
            delete count;
        }
        p = nullptr;
        count = nullptr;
    }
}

template <typename T>
inline void swap(shared_pointer<T> &lhs, shared_pointer<T> &rhs)
{
    using std::swap;
    swap(lhs.p, rhs.p);
    swap(lhs.count, rhs.count);
    swap(lhs.del, rhs.del);
}

template <typename T, typename... Args>
inline shared_pointer<T> make_sharedptr(Args &&... args)
{
    return shared_pointer<T>(new T(args...));
}

#endif // !SHARED_POINTER_H_
