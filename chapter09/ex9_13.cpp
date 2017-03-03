#include <list>
#include <vector>
#include <iostream>
using std::list;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    list<int> list1{1, 2, 3, 4, 5, 6, 7};
    vector<int> vec1(7, 14);
    vector<double> v1(list1.cbegin(), list1.cend());
    vector<double> v2(vec1.cbegin(), vec1.cend());

    for (const auto &d : v1)
        cout << d << " ";
    cout << endl;

    for (const auto &d : v2)
        cout << d << " ";
    cout << endl;

    return 0;
}