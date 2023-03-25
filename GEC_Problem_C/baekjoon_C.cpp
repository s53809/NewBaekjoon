#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void changeSTR(string& str) {
	for (int i = 0, str_size = str.size(); i < str_size; i++) {
		if (str[i] != 'a') {
			str[i] = str[i] - 1;
		}
		else {
			str[i] = 'z';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<string> ans = {
		"NLCS",
		"BHA",
		"KIS",
		"SJA"
	};

	vector<string> schools = {
		"northlondo",
		"branksomeh",
		"koreainter",
		"stjohnsbur"
	};

	string str;
	cin >> str;

	bool isCorrect = false;

	while (!isCorrect) {
		changeSTR(str);
		for (int i = 0; i < 4; i++) {
			if (str == schools[i]) {
				cout << ans[i];
				isCorrect = true;
				break;
			}
		}
	}
}