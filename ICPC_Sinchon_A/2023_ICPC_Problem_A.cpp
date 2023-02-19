#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string ans = "2023";
	int st = 0;

	int sub = 0;

	int N;
	cin >> N;
	for (int i = 2023; i <= N; i++) {
		string str = to_string(i);
		for (int j = 0, size = str.size(); j < size; j++) {
			if (ans[st] == str[j]) st++;
		}
		if (st >= 4) sub++;
		st = 0;
	}

	cout << sub;
}