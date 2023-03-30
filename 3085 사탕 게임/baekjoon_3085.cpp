#include <iostream>
#include <string>
#include <vector>
using namespace std;

int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };

int N;
vector<string> x;
int maxCount = 1;

void LYC() {
	for (int i = 0; i < N; i++) {
		int count = 1;
		for (int j = 0; j < N - 1; j++) {
			if (x[i][j] == x[i][j + 1]) {
				count++;
				maxCount = max(count, maxCount);
			}
			else {
				count = 1;
			}
		}
		for (int j = 0; j < N - 1; j++) {
			if (x[j][i] == x[j + 1][i]) {
				count++;
				maxCount = max(count, maxCount);
			}
			else {
				count = 1;
			}
		}
	}
}

void change(int posY, int posX) {
	for (int i = 0; i < 4; i++) {
		int dir_x = posX + d_x[i];
		int dir_y = posY + d_y[i];

		if (0 <= dir_x && dir_x < N && 0 <= dir_y && dir_y < N) {
			char temp = x[posY][posX];
			x[posY][posX] = x[dir_y][dir_x];
			x[dir_y][dir_x] = temp;

			LYC();

			temp = x[posY][posX];
			x[posY][posX] = x[dir_y][dir_x];
			x[dir_y][dir_x] = temp;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			change(i, j);
		}
	}

	cout << maxCount;
}