#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char chess_type_1[9][9] = {
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB"
};
char chess_type_2[9][9] = {
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW"
};
char chess[51][51] = { '0' };
char daeEp[3] = { "BW" };

int tamseck(int str_x, int str_y) {
	pair<int, int> ans = make_pair(0, 0);
	for (int i = str_y; i < str_y + 8; i++) {
		for (int j = str_x; j < str_x + 8; j++) {
			if (chess_type_1[i - str_y][j - str_x] != chess[i][j]) {
				ans.first++;
			}
			if (chess_type_2[i - str_y][j - str_x] != chess[i][j]) {
				ans.second++;
			}
		}
	}
	return min(ans.first, ans.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> chess[i];
	}
	int ans = 2e9;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int box = tamseck(j, i);
			if (ans > box) {
				ans = box;
			}
		}
	}
	cout << ans;
}