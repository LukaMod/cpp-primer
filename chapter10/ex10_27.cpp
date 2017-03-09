#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> vec1{1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6, 7, 7};
    vector<int> vec2;
    unique_copy(vec1.cbegin(), vec1.cend(), inserter(vec2, vec2.begin()));
    for (const auto &i : vec2)
        cout << i << " ";
    cout << endl;
    return 0;
}