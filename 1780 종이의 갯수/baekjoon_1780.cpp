#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<vector<int>> x;
vector<int> ans(3, 0);

void paperCut(int xPos, int yPos, int num) {
	bool isPaper = true;
	int paper = x[xPos][yPos];
	for (int i = xPos; i < xPos + num; i++) {
		for (int j = yPos; j < yPos + num; j++) {
			if (paper != x[i][j]) {
				isPaper = false;
				break;
			}
		}
		if (!isPaper) break;
	}
	if (isPaper) { ans[paper + 1]++; return; }

	int nextNum = num / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			paperCut(xPos + (i * nextNum), yPos + (j * nextNum), nextNum);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x[i][j];
		}
	}

	paperCut(0, 0, N);

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << '\n';
	}
}