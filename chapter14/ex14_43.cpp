#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec{2, 3, 5};
    modulus<int> mod;
    int input;
    cin >> input;
    auto divisible = [&](const int &i) { return mod(input, i); };
    auto iter = find_if(vec.begin(), vec.end(), divisible);
    cout << "Is divisible? " << (iter == vec.end() ? "Yes" : "No") << endl;
    return 0;
}