#include <iostream>
using namespace std;

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
	int firstFree = -1;

	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;
	for (int i = firstFree + 1; i < n; i++) {
		if (!taken[i] && areFriends[firstFree][i]) {
			taken[firstFree] = taken[i] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[i] = false;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		bool taken[10] = { false, };
		cout << countPairings(taken) << '\n';

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				areFriends[i][j] = false;
			}
		}
	}
}