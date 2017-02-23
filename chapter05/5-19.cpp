#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string rsp;
    do
    {
        cout << "please enter two string: ";
        string str1, str2;
        cin >> str1 >> str2;
        cout << (str1.length() < str2.length() ? str1 : str2) << " is shorter than the other"
             << "\n\n"
             << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
    return 0;
}