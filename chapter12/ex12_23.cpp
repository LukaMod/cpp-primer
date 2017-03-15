#include <iostream>
#include <string>

using namespace std;

int main()
{
    char *ca = new char[255]();
    strcat(ca, "hello");
    strcat(ca, " world");
    cout << ca << endl;
    delete[] ca;
    string a("hello"), b(" world");
    cout << a + b << endl;
    return 0;
}