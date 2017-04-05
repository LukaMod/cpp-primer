#include <iostream>
#include <utility>

using namespace std;

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void g(int &&i, int &j)
{
    cout << i << " " << j << endl;
}

int main()
{
    int i = 14;
    flip(g, i, 7);
    return 0;
}