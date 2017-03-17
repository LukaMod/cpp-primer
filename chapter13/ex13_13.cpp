#include <iostream>
#include <vector>

using namespace std;

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X &) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X &) { std::cout << "X& operater=(const X&)" << std::endl; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(X x, const X &rx)
{
    vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    vec.push_back(x);
}

int main()
{
    X *px = new X;
    f(*px, *px);
    delete px;
    return 0;
}