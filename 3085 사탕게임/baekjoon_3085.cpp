#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<string> x;
int d_x[] = { -1,1,0,0 };
int d_y[] = { 0,0,-1,1 };

vector<int> dic;

void Tamsek(int gap_1, int gap_2, bool isGaro) {
	initDic();
	int prevNum;

	if (isGaro) {
		prevNum = ColToInt(x[gap_1][0]);
		dic[prevNum] = 1;
	}
	else {
		prevNum = ColToInt(x[0][gap_1]);
		dic[prevNum] = 1;
	}
	for (int i = 1; i < N; i++) {
		if (isGaro) {
			if (ColToInt(x[gap_1][i]) == prevNum) {
				dic[ColToInt(x[gap_1][i])]++;
			}
			else {
				if (dic[ColToInt(x[gap_1][i])] = 0) {
					dic[ColToInt(x[gap_1][i])] = 1;
					
				}
			}
		}
	}
}

void initDic() {
	for (int i = 0; i < 4; i++) {
		dic[i] = 0;
	}
}

int ColToInt(char str) {
	if (str == 'C') {
		return 0;
	}
	if (str == 'P') {
		return 1;
	}
	if (str == 'Z') {
		return 2;
	}
	if (str == 'Y') {
		return 3;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	dic.resize(4);

	initDic();

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int u = 0; u < 4; u++) {
				int dir_x = j + d_x[u];
				int dir_y = i + d_y[u];
				if (dir_x >= 0 && dir_x < N && dir_y >= 0 && dir_y < N) {
					swap(x[i][j], x[dir_y][dir_x]);
					if (dir_x == j) {
						Tamsek(i, dir_y, false);
					}
					else {
						Tamsek(j, dir_x, true);
					}
				}
			}
		}
	}
}