#include <iostream>

using namespace std;

class numbered
{
  public:
    numbered()
    {
        static int unique = 7;
        mysn = ++unique;
    }
    numbered(const numbered &n) { mysn = n.mysn + 1; }

    int mysn;
};

void f(numbered s) { cout << s.mysn << endl; }

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}