#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string prestr, currstr;
    bool isRepeated = false;

    while (cin >> currstr)
    {
        if (!isupper(currstr[0]))
            continue;
        if (currstr == prestr)
        {
            cout << currstr << " repeated" << endl;
            isRepeated = true;
            break;
        }
        else
            prestr = currstr;
    }
    if (!isRepeated)
        cout << "no word was repeated." << endl;
    return 0;
}