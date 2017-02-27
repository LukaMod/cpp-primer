#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int a = 0, b = 0;
    cout << "please input two integers: ";
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
                throw runtime_error("divisor is 0");
            cout << static_cast<double>(a) / b << endl;
            cout << "please input two integers: ";
        }
        catch (runtime_error err)
        {
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n' || c == 'N')
                break;
            else
                cout << "please input two integers: ";
        }
    }
    return 0;
}