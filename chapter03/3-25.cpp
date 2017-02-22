#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
    {
	++*(scores.begin() + grade / 10);
    }
    for (auto i : scores)
	cout << i << " ";
    cout << endl;

    return 0;
}