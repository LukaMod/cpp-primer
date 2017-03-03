#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istringstream;
using std::getline;

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
    while (getline(cin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
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