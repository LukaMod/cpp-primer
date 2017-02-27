#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int add(int a, int b) { return a + b; }
int substract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main()
{
    vector<decltype(add) *> vec = {add, substract, multiply, divide};
    for (const auto &f : vec)
        cout << f(7, 14) << endl;

    return 0;
}