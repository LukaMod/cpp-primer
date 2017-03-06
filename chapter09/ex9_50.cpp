#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<string> vec{"1", "2", "3", "4", "5", "6", "7", "7.14"};
    int sumint = 0;
    double sumdouble = 0.0;
    for (const auto &v : vec)
        sumint += std::stoi(v);
    cout << sumint << endl;
    for (const auto &v : vec)
        sumdouble += std::stod(v);
    cout << sumdouble << endl;

    return 0;
}