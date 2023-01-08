#include <iostream>
#include <algorithm>
using namespace std;

int doHwaZi[101][101];
int N;

int d_x[] = { -1,1,0,0 };
int d_y[] = { 0,0,-1,1 };

void makeColorZongE(int posX, int posY) {
	for (int i = posY; i < posY + 10; i++) {
		for (int j = posX; j < posX + 10; j++) {
			doHwaZi[i][j] = 1;
		}
	}
}

int ZubyunCount(int posX, int posY) {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		int dir_x = posX + d_x[i];
		int dir_y = posY + d_y[i];

		if (doHwaZi[dir_y][dir_x] == 0) {
			count++;
		}
	}
	return count;
}

int DullaeGomsa(int maxX, int maxY) {
	int count = 0;
	for (int i = 1; i <= maxY; i++) {
		for (int j = 1; j <= maxX; j++) {
			if (doHwaZi[i][j] == 1) {
				count += ZubyunCount(j, i);
			}
		}
	}
	return count;
}

void PrintDoHwaZi(int printX, int printY) {
	for (int i = 1; i <= printY; i++) {
		for (int j = 1; j <= printX; j++) {
			cout << doHwaZi[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int maxX = 0;
	int maxY = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		makeColorZongE(a, b);
		maxX = max(maxX, a + 10);
		maxY = max(maxY, b + 10);
// 		PrintDoHwaZi(maxX, maxY);
// 		cout << '\n';
	}

	cout << DullaeGomsa(maxX, maxY);
	return 0;
}