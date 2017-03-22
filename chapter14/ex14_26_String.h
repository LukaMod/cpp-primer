#ifndef EX_14_26_STRING_H_
#define EX_14_26_STRING_H_

#include <memory>
#include <iostream>

class String
{
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator>=(const String &, const String &);

  public:
    String() : String(""){};
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    String(String &&) noexcept;
    String &operator=(String &&) noexcept;
    ~String();

    size_t size() const { return end - elem; }
    size_t length() const { return end - elem - 1; }
    char &operator[](std::size_t n) { return elem[n]; }
    const char &operator[](std::size_t n) const { return elem[n]; }
  private:
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void free();

    static std::allocator<char> alloc;

    char *elem;
    char *end;
};

bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator<(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>(const String &, const String &);
bool operator>=(const String &, const String &);

#endif