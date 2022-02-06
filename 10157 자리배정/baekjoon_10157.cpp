#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> x;
int C, R, K;

int d_x[] = { 0,1,0,-1 };
int d_y[] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> C >> R >> K;
	if (C * R < K) {
		cout << "0";
		return 0;
	}

	x.resize(R + 1);

	for (int i = 0; i < x.size(); i++) {
		x[i].resize(C + 1);
		fill(x[i].begin(), x[i].end(), false);
	}

	int sequence = 0;
	int garo = 1;
	int sero = 1;

	while (K != 1) {
		x[sero][garo] = true;
		int dist_x = garo + d_x[sequence];
		int dist_y = sero + d_y[sequence];
		if (dist_y <= R && dist_y > 0 && dist_x <= C && dist_x > 0) {
			if (x[dist_y][dist_x] == false) {
				sero = dist_y;
				garo = dist_x;
				K--;
			}
			else {
				sequence = (sequence + 1) % 4;
			}
		}
		else {
			sequence = (sequence + 1) % 4;
		}
	}
	cout << garo << ' ' << sero;
}

/*
1. y+
2. x+
3. y-
4. x-
*/