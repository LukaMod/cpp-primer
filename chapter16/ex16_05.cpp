#include <iostream>
#include <string>

using namespace std;

template <typename T>
void print(const T &a)
{
    for (const auto &elem : a)
        cout << elem << endl;
}

int main()
{
    string sa[] = {"he", "hi", "haha"};
    print(sa);
    return 0;
}