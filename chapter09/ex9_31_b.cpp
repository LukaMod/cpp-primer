#include <iostream>
#include <forward_list>
using std::cout;
using std::endl;
using std::forward_list;

int main()
{
    forward_list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = li.before_begin(), curr = li.begin();
    while (curr != li.end())
    {
        if (*curr % 2)
        {
            curr = li.insert_after(prev, *curr);
            ++curr, ++prev;
            ++curr, ++prev;
        }
        else
            curr = li.erase_after(prev);
    }
    for (const auto &i : li)
        cout << i << " ";
    cout << endl;
    return 0;
}