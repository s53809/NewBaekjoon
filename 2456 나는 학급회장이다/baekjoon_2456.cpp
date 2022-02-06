#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	vector<vector<int>> x;
	vector<int> hubo;
	vector<vector<int>> stac;

	cin >> N;

	x.resize(N);
	hubo.resize(3);
	stac.resize(3);
	hubo[0] = 0;
	hubo[1] = 0;
	hubo[2] = 0;
	for (int i = 0; i < 3; i++) {
		stac[i].resize(3);
		fill(stac[i].begin(), stac[i].end(), 0);
	}
	for (int i = 0; i < N; i++) {
		x[i].resize(3);
		cin >> x[i][0] >> x[i][1] >> x[i][2];
		stac[0][x[i][0] - 1]++;
		stac[1][x[i][1] - 1]++;
		stac[2][x[i][2] - 1]++;
		hubo[0] += x[i][0];
		hubo[1] += x[i][1];
		hubo[2] += x[i][2];
	}
	
	bool isGyop = false;
	int maximizeNum = 0;
	vector<int> gyopMemory;
	gyopMemory.push_back(maximizeNum);

	for (int i = 1; i < 3; i++) {
		if (hubo[maximizeNum] == hubo[i]) {
			gyopMemory.push_back(i);
			isGyop = true;
		}
		if (hubo[maximizeNum] < hubo[i]) {
			while (!gyopMemory.empty()) {
				gyopMemory.pop_back();
			}
			isGyop = false;
			maximizeNum = i;
			gyopMemory.push_back(maximizeNum);
		}
	}

	if (isGyop == false) {
		cout << maximizeNum + 1 << ' ' << hubo[maximizeNum];
	}

	for (int i = 0; i < 3; i++) {
		if (hubo[i] != hubo[maximizeNum]) {
			stac[i][0] = 0;
			stac[i][1] = 0;
			stac[i][2] = 0;
		}
	}

	int sequence = 2;
	bool hiThere = false;
	if (isGyop == true) {
		while (true) {
			int maximum = 0;
			for (int i = 1; i < 3; i++) {
				if (stac[maximum][sequence] == stac[i][sequence]) {
					hiThere = true;
				}
				if (stac[maximum][sequence] < stac[i][sequence]) {
					hiThere = false;
					maximum = i;
				}
				
			}
			if (hiThere) {
				if (sequence == 0) {
					cout << "0" << ' ' << hubo[maximizeNum];
					return 0;
				}
				sequence--;
			}
			else {
				cout << maximum + 1 << ' ' << hubo[maximizeNum];
				return 0;
			}
			hiThere = false;
		}
	}
}