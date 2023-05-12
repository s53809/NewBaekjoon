#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	string str;
	cin >> str;

	int str_size = str.length();
	queue<int> qu;
	vector<bool> check(str_size, false);

	int ans = 0;

	for (int i = 0; i < str_size; i++) {
		if (str[i] == 'B') qu.push(i);
		if (str[i] == 'C' && !qu.empty()) {
			int dist = qu.front();
			qu.pop();
			check[dist] = true;
			ans++;
		}
	}

	int aGetsu = 0;
	for (int i = 0; i < str_size && !qu.empty(); i++) {
		if (str[i] == 'A') aGetsu++;
		if (str[i] == 'B' && !check[i] && aGetsu > 0) {
			aGetsu--;
			check[i] = true;
			ans++;
		}
	}

	cout << ans;
}