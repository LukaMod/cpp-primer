#include <iostream>
#include <forward_list>
using std::cout;
using std::endl;
using std::forward_list;

int main()
{
    forward_list<int> flist{
        0, 1, 2, 3, 4, 5, 6, 7,
    };
    auto &prev = flist.before_begin();
    auto &curr = flist.begin();
    while (curr != flist.end())
    {
        if (*curr & 0x1)
        {
            curr = flist.erase_after(prev);
        }
        else
        {
            ++prev;
            ++curr;
        }
    }
    for (const auto &i : flist)
        cout << i << " ";
    cout << endl;

    return 0;
}