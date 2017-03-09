#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ifstream ifs("2-04.cpp");
    istream_iterator<string> in(ifs), eof;
    vector<string> vec;
    while (in != eof)
        vec.push_back(*in++);
    for (const auto &s : vec)
        cout << s << " ";
    return 0;
}