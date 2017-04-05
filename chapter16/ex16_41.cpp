#include <iostream>

using namespace std;

template <typename T>
auto sum(const T &lhs, const T &rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

int main()
{
    auto s = sum(123456789123456789, 123456789123456789);
    cout << s << endl;
    return 0;
}