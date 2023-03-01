#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<char>> str;
int N;

int d_x[] = { -1,0,1,-1,1,-1,0,1 };
int d_y[] = { -1,-1,-1,0,0,1,1,1 };

void Star(int x, int y, int num) {
	int ganGyuck = num / 3;
	for (int i = 0; i < 8; i++) {
		int dir_x = x + (d_x[i] * ganGyuck);
		int dir_y = y + (d_y[i] * ganGyuck);
		if (ganGyuck == 1) str[dir_y][dir_x] = '*';
		else Star(dir_x, dir_y, ganGyuck);
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	str.resize(N);
	for (int i = 0; i < N; i++) {
		str[i].resize(N);
		for (int j = 0; j < N; j++) {
			str[i][j] = ' ';
		}
	}

	Star((N / 2), (N / 2), N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << str[i][j];
		}
		cout << '\n';
	}
}