#ifndef EX7_43_H_
#define EX7_43_H_

class NoDefault
{
  public:
    NoDefault(int i) {}
};

class C
{
  public:
    C() : no(0) {}
  private:
    NoDefault no;
}

#endif