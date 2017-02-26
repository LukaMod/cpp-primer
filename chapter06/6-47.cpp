#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void print(const vector<int> &vec, int index)
{
#ifndef NDEBUG
    cout << "vector size: " << vec.size() << endl;
#endif
    if (index == vec.size())
        return;
    cout << vec[index++] << " ";
    print(vec, index);
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(vec, 0);
    cout << endl;
    return 0;
}