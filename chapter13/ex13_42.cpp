#include <iostream>

#include "ex13_42_TextQuery.h"
#include "ex13_42_QueryResult.h"

using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (1)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream file("input.txt");
    runQueries(file);
    return 0;
}