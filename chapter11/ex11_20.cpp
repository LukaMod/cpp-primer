#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        auto pr = word_count.insert({word, 1});
        if (!pr.second)
            ++pr.first->second;
    }
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << (w.second > 1 ? " times" : " time") << endl;
    return 0;
}