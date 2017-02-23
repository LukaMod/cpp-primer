#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string maxword, preword, currword;
    int count = 0, maxcount = 0;
    if (cin >> preword)
    {
        count = 1;
        while (cin >> currword)
        {
            if (currword == preword)
                ++count;
            else
            {
                preword = currword;
                count = 1;
            }
            if (count > maxcount)
            {
                maxcount = count;
                maxword = currword;
            }
        }
    }
    if (maxcount == 1)
        cout << "No word was repeated." << endl;
    else
        cout << maxword << " occurs " << maxcount << " times." << endl;
    return 0;
}