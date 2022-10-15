#include <iostream>
#include <algorithm>
using namespace std;

pair<int,bool> pan[5][5];
bool isChecked[5][5];

bool alreadyDaegak = false;
bool alreadyReverse = false;

int daegak_x[] = { 0,1,2,3,4 };
int daegak_y[] = { 0,1,2,3,4 };

int reverseDaegak_x[] = { 4,3,2,1,0 };
int reverseDaegak_y[] = { 0,1,2,3,4 };

int sayBingo = 0;

void checkBingo(int x, int y) {
	pan[x][y].second = true;
	bool isDaegak = false;
	bool isReverseDaegak = false;
	for (int i = 0; i < 5; i++) {
		if (x == daegak_x[i]) {
			if (y == daegak_y[i]) {
				isDaegak = true;
			}
		}
		if (x == reverseDaegak_x[i]) {
			if (y == reverseDaegak_y[i]) {
				isReverseDaegak = true;
			}
		}
	}

	bool isGaroBingo = true;
	bool isSeroBingo = true;

	for (int i = 0; i < 5; i++) {
		if (!pan[x][i].second || isChecked[x][0]) {
			isGaroBingo = false;
		}
		if (!pan[i][y].second || isChecked[0][y]) {
			isSeroBingo = false;
		}
	}

	if (isGaroBingo) {
		isChecked[x][0] = true;
		sayBingo++;
	}
	if (isSeroBingo) {
		isChecked[0][y] = true;
		sayBingo++;
	}

	bool isDaegakBingo = false;
	bool isReverseDaegakBingo = false;

	if (isDaegak && !alreadyDaegak) {
		isDaegakBingo = true;
		for (int i = 0; i < 5; i++) {
			if (!pan[daegak_y[i]][daegak_x[i]].second) {
				isDaegakBingo = false;
			}
		}
	}
	if (isReverseDaegak && !alreadyReverse) {
		isReverseDaegakBingo = true;
		for (int i = 0; i < 5; i++) {
			if (!pan[reverseDaegak_y[i]][reverseDaegak_x[i]].second) {
				isReverseDaegakBingo = false;
			}
		}
	}

	if (isDaegakBingo) {
		alreadyDaegak = true;
		sayBingo++;
	}
	else if (isReverseDaegakBingo) {
		alreadyReverse = true;
		sayBingo++;
	}
}

pair<int, int> isMatch(int sahwae) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (pan[i][j].first == sahwae) {
				return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> pan[i][j].first;
			pan[i][j].second = false;
			isChecked[i][j] = false;
		}
	}

	for (int i = 0; i < 25; i++) {
		int sahwae;
		cin >> sahwae;
		pair<int, int> Pos = isMatch(sahwae);
		if (Pos.first == -1) {
			continue;
		}
		else {
			checkBingo(Pos.first, Pos.second);
			if (sayBingo >= 3) {
				cout << i + 1;
				return 0;
			}
		}
	}

	
}