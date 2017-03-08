#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int i = 7;
    auto f = [&i]() -> bool {
        if (i)
            --i;
        return i == 0;
    };
    while (i)
    {
        f();
        cout << i << " ";
    }
    f();
    cout << i << endl;
    return 0;
}