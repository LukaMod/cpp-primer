#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec1 = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> vec2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto size = vec1.size() > vec2.size() ? vec2.size() : vec1.size();
    for (decltype(size) i = 0; i != size; ++i)
    {
        if (vec1[i] != vec2[i])
        {
            cout << "false" << endl;
            break;
        }
        if (i == size - 1)
            cout << "true" << endl;
    }
    return 0;
}