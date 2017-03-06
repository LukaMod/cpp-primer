#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main()
{
    string number{"0123456789"};
    string alpha{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string str{"ab2c3d7R4E6"};

    cout << "numeric characters: ";
    for (string::size_type pos = 0; (pos = str.find_first_of(number, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << endl;
    cout << "alphabetic characters: ";
    for (string::size_type pos = 0; (pos = str.find_first_of(alpha, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << endl;

    cout << "numeric characters: ";
    for (string::size_type pos = 0; (pos = str.find_first_not_of(alpha, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << endl;
    cout << "alphabetic characters: ";
    for (string::size_type pos = 0; (pos = str.find_first_not_of(number, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << endl;

    return 0;
}