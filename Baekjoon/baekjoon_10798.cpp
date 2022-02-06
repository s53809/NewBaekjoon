#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str[5];
	int maxLength = 0;

	for (int i = 0; i < 5; i++) {
		cin >> str[i];
		if (str[i].length() > maxLength) {
			maxLength = str[i].length();
		}
	}

	for (int i = 0; i < maxLength; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j].length() > i) {
				cout << str[j][i];
			}
		}
	}
	return 0;
}