#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	string str;
	vector<char> max_str;
	int max = 0;
	cin >> str;
	unordered_map<char, int> hashs_map;
	for (int i = 0; i < str.size(); i++) {
		char buf = toupper(str.at(i));
		hashs_map[buf] += 1;
		if (max < hashs_map[buf]) {
			max_str.clear();
			max = hashs_map[buf];
			max_str.push_back(buf);
		}
		else if (max == hashs_map[buf]) {
			max_str.push_back(buf);
		}
	}
	if (max_str.size() == 1) {
		cout << max_str.at(0) << endl;
	}
	else {
		cout << "?" << endl;
	}
	return 0;
}