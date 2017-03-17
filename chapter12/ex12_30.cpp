#include <iostream>

#include "ex12_27_a.h"
#include "ex12_27_b.h"

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
    ifstream ifs("input.txt");
    runQueries(ifs);

    return 0;
}