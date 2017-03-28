#include <iostream>
#include <string>

using namespace std;

template <typename T, unsigned size>
T *_begin(T (&a)[size])
{
    return a;
}

template <typename T, unsigned size>
T *_end(T (&a)[size])
{
    return a + size;
}

int main()
{
    std::string sa[] = {"he", "hi", "haha"};
    *cbegin(sa);
    std::cout << *_begin(sa) << std::endl;
    std::cout << *(_end(sa) - 1) << std::endl;
    return 0;
}