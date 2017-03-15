#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    int n = 10;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    string s;
    string *q = p;
    while (cin >> s && q != p + n)
        alloc.construct(q++, s);
    while (q != p)
    {
        cout << *--q << " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
    return 0;
}