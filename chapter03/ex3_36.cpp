#include <iostream>
#include <vector>
#include <iterator>

using std::vector;
using std::begin;
using std::end;
using std::cout;
using std::endl;

int main()
{
    int ia1[4] = {2, 3, 2, 1};
    int ia2[4] = {2, 3, 2, 2};

    auto beg1 = begin(ia1), beg2 = begin(ia2);
    auto last1 = end(ia1), last2 = end(ia2);

    bool isEqual = true;

    if (last1 - beg1 != last2 - beg2)
        isEqual = false;
    else
    {
        while (beg1 != last1 && beg2 != last2)
            if (*beg1++ != *beg2++)
                isEqual = false;
    }

    if (isEqual)
        cout << "The two arrays are equal." << endl;
    else
        cout << "The two arrays are not equal." << endl;

    vector<int> ivec1 = {1, 2, 3};
    vector<int> ivec2 = {1, 2, 3};
    if (ivec1 == ivec2)
        cout << "The two vectors are equal." << endl;
    else
        cout << "The two vectors are not equal." << endl;

    return 0;
}