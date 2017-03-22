#include <iostream>
#include <map>
#include <functional>
#include <string>

using namespace std;

auto add = [](int a, int b) { return a + b; };
auto min = [](int a, int b) { return a - b; };
auto mul = [](int a, int b) { return a * b; };
auto mod = [](int a, int b) { return a % b; };

int main()
{
    map<string, function<int(int, int)>> binops;
    binops.insert({"+", add});
    binops.insert({"-", min});
    binops.insert({"*", mul});
    binops.insert({"/", [](int a, int b) { return a / b; }});
    binops.insert({"%", mod});
    while (1)
    {
        cout << "please enter num operator num:" << endl;
        int a, b;
        string oper;
        cin >> a >> oper >> b;
        cout << binops[oper](a, b) << endl;
    }
    return 0;
}