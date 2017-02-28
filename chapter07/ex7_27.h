#ifndef EX7_27_H_
#define EX7_27_H_

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
    Screen &set(char ch);
    Screen &set(pos r, pos c, char ch);
    const Screen &display(std::ostream &os) const;
    Screen &display(std::ostream &os);

  private:
    void do_display(std::ostream &os) const { os << contents; }

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

inline Screen &Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    pos row = r * width;
    contents[cursor] = ch;
    return *this;
}

inline const Screen &Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}

Screen &Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
}

#endif