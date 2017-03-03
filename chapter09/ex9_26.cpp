#include <vector>
#include <list>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::end;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    vector<int> vec(ia, end(ia));
    list<int> lst(vec.cbegin(), vec.cend());
    for (auto &iter = vec.begin(); iter != vec.end();)
    {
        if (!(*iter & 0x1))
            iter = vec.erase(iter);
        else
            ++iter;
    }
    for (auto &iter = lst.begin(); iter != lst.end();)
    {
        if (*iter & 0x1)
            iter = lst.erase(iter);
        else
            ++iter;
    }
    for (const auto &i : vec)
        cout << i << " ";
    cout << endl;
    for (const auto &i : lst)
        cout << i << " ";
    cout << endl;

    return 0;
}