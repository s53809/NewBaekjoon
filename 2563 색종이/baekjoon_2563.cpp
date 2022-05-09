#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	x.resize(100);
	for (int i = 0; i < 100; i++) {
		x[i].resize(100);
		for (int j = 0; j < 100; j++) {
			x[i][j] = false;
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		int first, second;
		cin >> first >> second;

		for (int i = first; i < first + 10; i++) {
			for (int j = second; j < second + 10; j++) {
				if (i >= 0 && i < 100 && j >= 0 && j < 100) {
					x[i][j] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (x[i][j] == true) ans++;
		}
	}
	cout << ans;
}