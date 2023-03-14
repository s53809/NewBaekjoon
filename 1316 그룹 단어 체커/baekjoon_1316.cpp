#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int ans = 0;

	while (N--) {
		string str;
		cin >> str;
		bool isAlpha[26] = { false, };

		char lastChar = str[0];
		isAlpha[str[0] - 'a'] = true;
		bool isAns = true;

		for (int i = 1, str_size = str.size(); i < str_size; i++) {
			if (lastChar != str[i]) { 
				lastChar = str[i]; 
				if (isAlpha[str[i] - 'a']) {
					isAns = false; break;
				}
			}
			isAlpha[str[i] - 'a'] = true;
		}

		if (isAns) ans++;
	}

	cout << ans;
}