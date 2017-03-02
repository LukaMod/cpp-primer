#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

std::istream &func(std::istream &is)
{
    std::string buf;
    while (!(is >> buf).eof())
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    string str;
    func(cin) >> str;
    cout << str << std::endl;

    return 0;
}