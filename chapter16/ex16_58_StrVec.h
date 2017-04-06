#ifndef EX_16_58_STRVEC_H_
#define EX_16_58_STRVEC_H_

#include <string>
#include <memory>
#include <utility>

class StrVec
{
  public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec();

    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    template <typename... Args>
    void emplace_back(Args &&...);

  private:
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void reallocate();

    static std::allocator<std::string> alloc;

    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

template <typename... Args>
inline void StrVec::emplace_back(Args &&... args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif