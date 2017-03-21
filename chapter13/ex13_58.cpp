#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Foo
{
  public:
    Foo sorted() &&
    {
        sort(data.begin(), data.end());
        cout << "sorted() &&" << endl;
        return *this;
    }
    Foo sorted() const &
    {
        cout << "sorted() const &" << endl;
        return Foo(*this).sorted();
    }

  private:
    vector<int> data;
};

int main()
{
    Foo().sorted();
    Foo f;
    f.sorted();
    return 0;
}