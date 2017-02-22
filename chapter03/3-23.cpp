#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec(10, 7);
    for (auto it = vec.begin(); it != vec.end(); ++it)
	*it *= 2;
    for (int val : vec)
	cout << val << " ";
    cout << endl;

    return 0;
}