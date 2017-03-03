#include <vector>
#include <list>
#include <iostream>
using std::vector;
using std::list;
using std::cout;
using std::endl;

int main()
{
    list<int> li{1, 2, 3, 4, 5};
    vector<int> vec{1, 2, 3, 4, 5};
    cout << (vector<int>(li.cbegin(), li.cend()) == vec ? "equal" : "unequal") << endl;
    return 0;
}
