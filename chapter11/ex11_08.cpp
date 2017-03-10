#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<string> vec;
    string s;
    while (cin >> s)
    {
        if (find(vec.cbegin(), vec.cend(), s) == vec.cend())
            vec.push_back(s);
    }
    for (const auto &v : vec)
        cout << v << " ";
    cout << endl;

    return 0;
}