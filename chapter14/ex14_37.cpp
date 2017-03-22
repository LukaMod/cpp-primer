#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class same
{
  public:
    same() : i(0) {}
    same(const int &j) : i(j) {}
    bool operator()(const int &val)
    {
        return i == val;
    }

  private:
    int i;
};

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    replace_if(vec.begin(), vec.end(), same(3), 9);
    for (const int &i : vec)
        cout << i << " ";
    cout << endl;
}