#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

void printList(const list<int> &li)
{
    for (const auto &i : li)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst1, lst2, lst3;
    copy(vec.cbegin(), vec.cend(), inserter(lst1, lst1.begin()));
    copy(vec.cbegin(), vec.cend(), back_inserter(lst2));
    copy(vec.cbegin(), vec.cend(), front_inserter(lst3));

    printList(lst1);
    printList(lst2);
    printList(lst3);
    return 0;
}