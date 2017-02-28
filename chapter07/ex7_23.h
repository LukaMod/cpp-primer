#ifndef EX7_23_H_
#define EX7_23_H_

#include <string>

class Screen
{
  public:
    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    const char &get() const { return contents[cursor]; }
    const char &get(pos r, pos c) const;
    Screen &move(pos r, pos c);

  private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline const char &Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

#endif