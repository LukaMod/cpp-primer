#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
    ifstream ifs("input.txt");
    vector<string> input;
    map<string, set<decltype(input.size())>> dictionary;

    string text;
    while (getline(ifs, text))
    {
        input.push_back(text);
        int n = input.size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
            dictionary[word].insert(n);
    }

    while (1)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        auto found = dictionary.find(s);
        if (found != dictionary.end())
        {
            cout << s << " occurs " << found->second.size() << " "
                 << (found->second.size() > 1 ? "times" : "time") << endl;
            for (auto const &l : found->second)
                cout << "\t(line " << l + 1 << ") " << input[l] << endl;
        }
    }

    return 0;
}