#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::unique;
using std::stable_sort;
using std::partition;
using std::for_each;

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
    auto wc = partition(words.begin(), words.end(),
                        [sz](const string &s) { return s.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), wc,
             [](const string &s) { cout << s << " "; });
    cout << endl;
}

int main()
{
    vector<string> vec{"hello", "hehe", "ah", "bitch", "hehe", "haha", "ha", "ia"};
    biggies(vec, 3);
    return 0;
}