#include <iostream>
#include <string>

using namespace std;

template<typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs)
		return 1;
	if (rhs < lhs)
		return -1;
	return 0;
}

int main()
{
	cout << compare(1, 2) << endl;
	cout << compare(string("he"), string("haha")) << endl;
	return 0;
}