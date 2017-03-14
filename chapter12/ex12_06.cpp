#include <vector>
#include <iostream>

using namespace std;

vector<int> *f()
{
    return new vector<int>();
}

void print(vector<int> vec)
{
    for (const int &v : vec)
        cout << v << " ";
    cout << endl;
}

void use_f()
{
    vector<int> *p = f();
    int i;
    while (cin >> i)
        p->push_back(i);
    print(*p);
    delete p;
}

int main()
{
    use_f();
    return 0;
}