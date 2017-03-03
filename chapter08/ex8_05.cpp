#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using std::ifstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

void fileToVec(const string &file, vector<string> &vec)
{
    ifstream ifs(file);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
            vec.push_back(buf);
    }
}

int main()
{
    vector<string> vec;
    fileToVec("ex8_05.cpp", vec);
    for (const auto &s : vec)
        cout << s << endl;
    return 0;
}