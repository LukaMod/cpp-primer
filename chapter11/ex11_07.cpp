#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    map<string, vector<string>> family;
    string lastName;
    cout << "please enter a lastName: " << endl;
    while (cin >> lastName && lastName != "@q")
    {
        family[lastName];
        cout << "please enter several childNames:(@q to quit!) " << endl;
        string childName;
        while (cin >> childName && childName != "@q")
            family[lastName].push_back(childName);
        cout << "please enter a lastName: " << endl;
    }
    for (const auto &f : family)
    {
        cout << f.first << " : ";
        for (const auto &sec : f.second)
            cout << sec << " ";
        cout << endl;
    }

    return 0;
}