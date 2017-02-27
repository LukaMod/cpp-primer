#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "bool\t\tis " << sizeof(bool) << " bytes." << endl;
    cout << "char\t\tis " << sizeof(char) << " bytes." << endl;
    cout << "wchar_t\t\tis " << sizeof(wchar_t) << " bytes." << endl;
    cout << "char16_t\tis " << sizeof(char16_t) << " bytes." << endl;
    cout << "char32_t\tis " << sizeof(char32_t) << " bytes." << endl;
    cout << "short\t\tis " << sizeof(short) << " bytes." << endl;
    cout << "int\t\tis " << sizeof(int) << " bytes." << endl;
    cout << "long\t\tis " << sizeof(long) << " bytes." << endl;
    cout << "long long\tis " << sizeof(long long) << " bytes." << endl;
    cout << "float\t\tis " << sizeof(float) << " bytes." << endl;
    cout << "double\t\tis " << sizeof(double) << " bytes." << endl;
    cout << "long double\tis " << sizeof(long double) << " bytes." << endl;
    cout << endl;

    return 0;
}