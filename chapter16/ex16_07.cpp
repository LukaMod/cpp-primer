#include <iostream>
#include <string>

using namespace std;

template <typename T, unsigned size>
constexpr unsigned _size(const T (&)[size])
{
    return size;
}

int main()
{
    std::string sa[] = {"he", "hi", "haha"};
    cout << _size(sa) << endl;
    return 0;
}