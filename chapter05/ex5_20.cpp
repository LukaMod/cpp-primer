#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string prestr, currstr;
    cin >> prestr;
    while (cin >> currstr)
    {
        if (currstr == prestr)
        {
            cout << currstr << " repeated" << endl;
            break;
        }
    }
    if (prestr.empty() || currstr != prestr)
        cout << "no word was repeated." << endl;
    return 0;
}