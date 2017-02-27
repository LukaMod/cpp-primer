#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec;
    int val;
    while (cin >> val)
        vec.push_back(val);
    if (vec.empty())
    {
        cout << "Empty vector!" << endl;
        return -1;
    }
    else if (vec.size() == 1)
        cout << vec[0] << endl;
    else
    {
        for (decltype(vec.size()) i = 0; i != vec.size() - 1; ++i)
            cout << vec[i] + vec[i + 1] << " ";
    }
    cout << endl;

    decltype(vec.size()) size = (vec.size() + 1) / 2;
    for (decltype(size) i = 0; i != size; ++i)
        cout << vec[i] + vec[vec.size() - 1 - i] << " ";
    cout << endl;

    return 0;
}