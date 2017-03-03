#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istringstream;
using std::getline;
using std::ifstream;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream ifs("personInfo.txt");
    if (ifs)
    {
        while (getline(ifs, line))
        {
            PersonInfo info;
            record.clear();
            record.str(line);
            record >> info.name;
            while (record >> word)
                info.phones.push_back(word);
            people.push_back(info);
        }
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    for (const auto &p : people)
    {
        cout << p.name << " ";
        for (const auto &ph : p.phones)
            cout << ph << " ";
        cout << endl;
    }

    return 0;
}