#include <iostream>
#include <fstream>

#include "ex12_19_b.h"
#include "ex12_19_a.h"

using namespace std;

int main()
{
    StrBlob blob;
    ifstream ifs("input.txt");
    string line;
    while (getline(ifs, line))
        blob.push_back(line);
    for (StrBlobPtr iter(blob.begin()); iter.unequal(blob.end()); iter.incr())
    {
        cout << iter.deref() << endl;
    }
    return 0;
}