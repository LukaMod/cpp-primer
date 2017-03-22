#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class SizeCheck
{
  public:
    SizeCheck(size_t l = 0, size_t u = 0) : lower(l), upper(u) {}
    bool operator()(const string &s) const
    {
        return s.size() >= lower && s.size() < upper;
    }

  private:
    size_t lower;
    size_t upper;
};

int main()
{
    ifstream ifs("ex14_39.cpp");
    unsigned cnt_9 = 0, cnt_10 = 0;
    SizeCheck sc9(1, 9), sc10(1, 10);
    string str;
    while (ifs >> str)
    {
        if (sc9(str))
            ++cnt_9;
        if (!sc10(str))
            ++cnt_10;
    }
    cout << "words that are sizes 1 through 9: " << cnt_9 << endl;
    cout << "words that are sizes 10 or more: " << cnt_10 << endl;
    return 0;
}