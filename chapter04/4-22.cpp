#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned grade;
    while (cin >> grade)
    {
        cout << ((grade > 90) ? "high pass"
                              : (grade >= 75) ? "pass"
                                              : (grade < 60) ? "fail" : "low pass")
             << endl;
        if (grade > 90)
            cout << "high pass" << endl;
        else if (grade >= 75)
            cout << "pass" << endl;
        else if (grade >= 60)
            cout << "low pass" << endl;
        else
            cout << "fail" << endl;
    }
    return 0;
}