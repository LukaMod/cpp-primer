#include <iostream>
#include <numeric>
#include <vector>
using std::cout;
using std::endl;
using std::accumulate;
using std::vector;

int main()
{
    vector<int> vec{1, 9, 9, 3, 0, 7, 1, 4};
    cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
    return 0;
}