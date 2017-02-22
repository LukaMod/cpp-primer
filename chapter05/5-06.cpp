#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    unsigned grade = 0;
    string lettergrade;
    while (cin >> grade)
    {
        lettergrade = grade < 60 ? scores[0]
                                 : grade == 100 ? scores[(grade - 50) / 10]
                                                : grade % 10 > 7 ? scores[(grade - 50) / 10] + '+'
                                                                 : grade % 10 < 3 ? scores[(grade - 50) / 10] + '-'
                                                                                  : scores[(grade - 50) / 10];
        cout << lettergrade << endl;
    }

    return 0;
}