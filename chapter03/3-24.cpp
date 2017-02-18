#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> vec;
	int val;
	while (cin >> val)
		vec.push_back(val);
	if (vec.empty()) {
		cout << "Empty vector!" << endl;
		return -1;
	}
	else if (vec.size() == 1) {
		cout << vec[0] << " at least 2 number!" << endl;
		return -2;
	}
	else {
		for (auto it = vec.cbegin(); it != vec.cend() - 1; ++it)
			cout << *it + *(it + 1) << " ";
		cout << endl;
	}
	for (auto beg = vec.cbegin(), end = vec.cend() - 1; beg <= end; ++beg, --end)
		cout << *beg + *end << " ";
	cout << endl;

	return 0;
}