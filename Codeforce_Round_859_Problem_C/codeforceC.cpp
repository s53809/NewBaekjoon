#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	int N;
	string str;
	vector<int> alphaBet(26);
	while (T--) {
		fill(alphaBet.begin(), alphaBet.end(), -1);
		cin >> N >> str;
		alphaBet[str[0] - 'a'] = 0;
		str[0] = '0';
		bool isCorrect = true;
		for (int i = 1; i < N; i++) {
			if (alphaBet[str[i] - 'a'] == -1) {
				if (str[i - 1] == '0') alphaBet[str[i] - 'a'] = 1;
				else alphaBet[str[i] - 'a'] = 0;
				str[i] = alphaBet[str[i] - 'a'] + '0';
			}
			else {
				str[i] = alphaBet[str[i] - 'a'] + '0';
				if (str[i] == str[i - 1]) { isCorrect = false; break; }
			}
		}

		if (isCorrect) cout << "YES\n";
		else cout << "NO\n";
	}
}