#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ifstream ifs("ex10_29.cpp");
    istream_iterator<string> in(ifs), eof;
    vector<string> vec(in, eof);
    for (const auto &s : vec)
        cout << s << " ";
    cout << endl;
    return 0;
}