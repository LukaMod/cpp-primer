#include <vector>

#include "ex14_35.h"

using namespace std;

int main()
{
    InputString is(cin);
    vector<string> vec;
    for (string s; !(s = is()).empty();)
        vec.push_back(s);
    for (const string &v : vec)
        cout << v << " ";
    cout << endl;
}