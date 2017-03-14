#include <vector>
#include <iostream>
#include <memory>

using namespace std;

shared_ptr<vector<int>> f()
{
    return make_shared<vector<int>>();
}

void print(vector<int> vec)
{
    for (const int &v : vec)
        cout << v << " ";
    cout << endl;
}

void use_f()
{
    shared_ptr<vector<int>> p = f();
    int i;
    while (cin >> i)
        p->push_back(i);
    print(*p);
}

int main()
{
    use_f();
    return 0;
}