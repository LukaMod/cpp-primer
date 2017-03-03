#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec1{1, 2, 3, 4, 6};
    vector<int> vec2{1, 2, 3, 4, 5};
    cout << (vec1 == vec2 ? "equal" : "unequal") << endl;
    return 0;
}
