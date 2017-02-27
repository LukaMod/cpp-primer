#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    int ia[10];
    for (size_t i = 0; i < 10; ++i)
        ia[i] = i;

    int ia2[10];
    for (size_t i = 0; i < 10; i++)
        ia2[i] = ia[i];

    vector<int> ivec;
    for (decltype(ivec.size()) i = 0; i < 10; ++i)
        ivec.push_back(i);
    vector<int> ivec2(ivec);

    for (auto i : ia2)
        cout << i << " ";
    cout << endl;

    for (auto v : ivec2)
        cout << v << " ";
    cout << endl;

    return 0;
}