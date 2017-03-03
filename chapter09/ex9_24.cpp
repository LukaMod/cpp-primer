#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    cout << vec.at(0) << endl;
    cout << vec[0] << endl;
    cout << vec.front() << endl;
    cout << *vec.begin() << endl;

    cout << vec[0] << endl;
}