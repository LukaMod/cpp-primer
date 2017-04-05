#include <string>
#include <iostream>

#include "ex16_29.h"

using namespace std;

int main()
{
    Blob<string> b1{"hi", "hello"};
    Blob<string> b2;
    b1.pop_back();
    b2.push_back("hi");
    cout << (b1 == b2) << endl;
    b1.push_back("oh");
    cout << b1.front() << " "
         << b1.back() << " "
         << b1[0] << endl;
    return 0;
}