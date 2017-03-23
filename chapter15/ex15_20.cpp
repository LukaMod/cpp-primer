class Base
{
    void memfcn(Base &b) { b = *this; }
  protected:
    int prot_mem;
};

struct Pub_Derv : public Base
{
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base
{
    void memfcn(Base &b) { b = *this; }
};

struct prot_Derv : protected Base
{
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv
{
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protect : public prot_Derv
{
    void memfcn(Base &b) { b = *this; }
};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protect dd3;

    Base *p = &d1;
    p = &d2;
    p = &d3;
    p = &dd1;
    p = &dd2;
    p = &dd3;
}