#include <iostream>
#include <string>
#include <fstream>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;

int main()
{
    ifstream ifs("head.h");
    string filter("aceimnorsuvwxz");
    string longest;
    if (ifs)
    {
        string word;
        while (ifs >> word)
        {
            if (word.find_first_not_of(filter) == string::npos && word.size() > longest.size())
                longest = word;
        }
    }
    cout << longest << endl;
    return 0;
}