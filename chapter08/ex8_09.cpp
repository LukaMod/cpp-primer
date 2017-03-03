#include <iostream>
#include <sstream>
#include <string>
using std::istream;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

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
    istringstream iss("hello world");
    func(iss);
    return 0;
}