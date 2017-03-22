#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class lamda
{
  public:
    lamda(size_t n = 0) : sz(n) {}

    bool operator()(const string &a, const string &b) const
    {
        return a.size() < b.size();
    }
    bool operator()(const string &s) const
    {
        return s.size() >= sz;
    }

  private:
    size_t sz;
};

class prt
{
  public:
    prt(int n = 0) : i(n) {}
    void operator()(const string &s) const
    {
        cout << s << " ";
    }

  private:
    int i;
};

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return ctr > 1 ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                lamda());
    auto wc = find_if(words.begin(), words.end(),
                      lamda(sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
             prt());
    cout << endl;
}

int main()
{
    vector<string> vec{"hello", "hehe", "ah", "bitch", "hehe", "haha", "ha", "ia"};
    biggies(vec, 3);
    return 0;
}