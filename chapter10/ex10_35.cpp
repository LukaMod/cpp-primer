#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    if (!vec.empty())
    {
        for (auto iter = vec.cend(); iter != vec.cbegin();)
            cout << *--iter << " ";
        cout << endl;
    }
    return 0;
}