#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> x;
int cnt[2] = { 0,0 };

void count(int xPos, int yPos, int num) {
	int value = x[yPos][xPos];
	bool isZongE = true;
	for (int i = yPos; i < yPos + num; i++) {
		for (int j = xPos; j < xPos + num; j++) {
			if (x[i][j] != value) {
				isZongE = false;
				break;
			}
		}
		if (!isZongE) break;
	}

	if (isZongE) { cnt[value]++; return; }

	int nextNum = num / 2;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			count(xPos + (j * nextNum), yPos + (i * nextNum), nextNum);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x[i][j];
		}
	}

	count(0, 0, N);
	
	cout << cnt[0] << '\n' << cnt[1];
}