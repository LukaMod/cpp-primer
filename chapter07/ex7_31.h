#ifndef EX7_31_H_
#define EX7_31_H_

class Y;

class X
{
    Y *py = nullptr;
};

class Y
{
    X x;
};

#endif