#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::fill_n;

int main()
{
    int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fill_n(ia, sizeof(ia) / sizeof(*ia), 0);
    for (const int &i : ia)
        cout << i << " ";
    cout << endl;

    return 0;
}