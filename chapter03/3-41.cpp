#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> vec(begin(a), end(a));
	for (int i : vec)
		cout << i << " ";
	cout << endl;
	return 0;
}