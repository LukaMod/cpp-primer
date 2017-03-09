#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    for (auto riter = vec.crbegin(); riter != vec.crend(); ++riter)
        cout << *riter << " ";
    cout << endl;
    return 0;
}