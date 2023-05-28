#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> x;
int dp_1[2][3];
int dp_2[2][3];

int canGo[3][3] = {
	{0,1,-1},
	{0,1,2},
	{1,2,-1}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	x.resize(3);
	
	int k = 1;
	int highAns = 0;

	for (int floor = 0; floor < N; floor++) {
		for (int j = 0; j < 3; j++) {
			cin >> x[j];
		}

		for (int i = 0; i < 3; i++) { //i열 검사
			dp_1[k][i] = 0;
			for (int j = 0; j < 3; j++) { //i - 1열에서 가져올 수 있는 값중 가장 최댓값
				if (canGo[i][j] == -1) continue;
				dp_1[k][i] = max(dp_1[k][i], x[i] + dp_1[1 - k][canGo[i][j]]);
				highAns = max(highAns, dp_1[k][i]);
			}
		}
		for (int i = 0; i < 3; i++) { //i열 검사
			dp_2[k][i] = 2e9;
			for (int j = 0; j < 3; j++) { //i - 1열에서 가져올 수 있는 값중 가장 최솟값
				if (canGo[i][j] == -1) continue;
				dp_2[k][i] = min(dp_2[k][i], x[i] + dp_2[1 - k][canGo[i][j]]);
			}
		}

		k = 1 - k;
	}
	cout << highAns << ' ';

	k = 1 - k;
	int lowAns = 2e9;
	for (int i = 0; i < 3; i++) {
		lowAns = min(lowAns, dp_2[k][i]);
	}

	cout << lowAns << ' ';
}