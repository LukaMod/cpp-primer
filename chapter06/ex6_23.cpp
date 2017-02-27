#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

void print(const int *pi)
{
    if (pi)
        cout << *pi << endl;
}

void print(const char *pc)
{
    if (pc)
        while (*pc)
            cout << *pc++;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << ia[i] << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print(&i);
    print(j, sizeof j / sizeof(int));
    print(begin(j), end(j));
    return 0;
}