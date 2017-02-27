#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

int main()
{
    const char ca1[6] = "hello";
    const char ca2[6] = "world";
    const size_t size = strlen(ca1) + strlen(" ") + strlen(ca2) + 1;
    char cstr[size];
    strcpy(cstr, ca1);
    strcat(cstr, " ");
    strcat(cstr, ca2);
    cout << cstr << endl;
    return 0;
}