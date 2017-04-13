#ifndef QUIZ_H_
#define QUIZ_H_

#include <bitset>
#include <string>
#include <iostream>

template <unsigned N>
class quiz
{
  public:
    quiz() = default;
    quiz(std::string &s) : b(s) {}

    void update(unsigned i, bool ans) { b.set(i, ans); }

  private:
    template <unsigned M>
    friend std::ostream &operator<<(std::ostream &os, const quiz<M> &q);

    std::bitset<N> b;
};

template <unsigned M>
std::ostream &operator<<(std::ostream &os, const quiz<M> &q)
{
    os << q.b;
    return os;
}

#endif // !QUIZ_H_
