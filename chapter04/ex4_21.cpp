#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};
    for (auto &v : vec)
        v = v % 2 ? 2 * v : v;
    for (const auto &v : vec)
        cout << v << " ";
    cout << endl;
    return 0;
}