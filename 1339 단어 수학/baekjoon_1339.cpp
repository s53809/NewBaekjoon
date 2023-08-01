#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	vector<int> alphabets(26, 0);
	vector<string> str;

	int N;
	cin >> N;
	str.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		for (int j = 0, str_size = str[i].size(); j < str_size; j++) {
			alphabets[str[i][j] - 'A'] += pow(10, str_size - j - 1);
			//cout << str[i][j] << ' ' << alphabets[str[i][j] - 'A'] << '\n';
		}
	}

	sort(alphabets.begin(), alphabets.end(), [](int a, int b) {return a > b; });

	int num = 9;
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += alphabets[i] * num--;
	}
	cout << ans;
}