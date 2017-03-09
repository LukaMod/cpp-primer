#include <iterator>
#include <fstream>
#include <iostream>

using namespace std;

void func(ifstream &ifs, ofstream &ofs1, ofstream &ofs2)
{
    istream_iterator<int> in(ifs), eof;
    ostream_iterator<int> odd(ofs1, " "), even(ofs2, "\n");
    while (in != eof)
    {
        if (*in % 2)
            odd = *in;
        else
            even = *in;
        ++in;
    }
}

int main()
{
    ifstream ifs("number.txt");
    ofstream odd("odd.txt"), even("even.txt");
    func(ifs, odd, even);

    return 0;
}