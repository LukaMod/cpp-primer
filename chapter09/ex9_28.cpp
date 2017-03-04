#include <iostream>
#include <forward_list>
#include <string>
using std::cout;
using std::endl;
using std::forward_list;
using std::string;

void findInsert(forward_list<string> &flist, const string &find, const string &insert)
{
    auto &prev = flist.cbefore_begin();
    for (auto &curr = flist.cbegin(); curr != flist.cend(); ++curr, ++prev)
    {
        if (*curr == find)
        {
            flist.insert_after(curr, insert);
            return;
        }
    }
    flist.insert_after(prev, insert);
}

int main()
{
    forward_list<string> flst{"a", "b", "x", "c", "d"};
    findInsert(flst, "x", "y");
    for (const auto &s : flst)
        cout << s << " ";
    cout << endl;
    return 0;
}