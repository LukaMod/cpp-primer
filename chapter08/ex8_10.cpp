#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using std::ifstream;
using std::vector;
using std::string;
using std::istringstream;
using std::getline;
using std::cerr;
using std::cout;
using std::endl;

int main()
{
    ifstream ifs("ex9_10.cpp");
    vector<string> vec;
    if (ifs)
    {
        string line;
        while (getline(ifs, line))
            vec.push_back(line);
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    for (const auto &s : vec)
    {
        istringstream iss(s);
        string word;
        while (iss >> word)
            cout << word << endl;
    }
    return 0;
}