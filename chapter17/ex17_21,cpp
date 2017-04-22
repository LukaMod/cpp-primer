#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <sstream>

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const smatch& m)
{
	if (m[1].matched)
		return m[3].matched && (!m[4].matched || m[4] == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

string format(const smatch& m)
{
	return m[2].str() + "-" + m[5].str() + "-" + m[7].str();
}

int main()
{
	vector<PersonInfo> people;
	ifstream ifs("record.txt");

	if (ifs) {
		string line, word;
		while (getline(ifs, line)) {
			PersonInfo info;
			istringstream record(line);
			record >> info.name;
			while (record >> word)
				info.phones.push_back(word);
			people.push_back(info);
		}
	}

	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	smatch m;

	for (const auto& entry : people) {
		ostringstream formatted, badNums;
		for (const auto& nums : entry.phones) {
			for (sregex_iterator it(nums.begin(), nums.end(), r), end_it; it != end_it; ++it) {
				if (!valid(*it))
					badNums << " " << nums;
				else
					formatted << " " << format(*it);
			}
		}

		if (badNums.str().empty())
			cout << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << " invalid numbers: " << badNums.str() << endl;
	}

	return 0;
}