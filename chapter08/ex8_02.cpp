#include <iostream>
#include <string>
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::string;

istream &func(istream &is)
{
    string buf;
    while (!(is >> buf).eof())
        cout << buf << endl;
    is.clear();
    return is;
}

int main()
{
    string str;
    func(cin) >> str;
    cout << str << endl;

    return 0;
}