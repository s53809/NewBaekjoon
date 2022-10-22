#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, D, K, C;
vector<int> x;
vector<bool> checkChobap;

int maxLine = 0;
int maxGazi = 0;

int gaziCalculator(int cur) {
	int curGazi = 0;
	for (int i = 0; i < K; i++) {
		if (!checkChobap[x[(cur + i) % N]]) {
			curGazi++;
			checkChobap[x[(cur + i) % N]] = true;
		}
	}
	fill(checkChobap.begin(), checkChobap.end(), false);
	checkChobap[C] = true;
	return curGazi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> D >> K >> C;

	x.resize(N);
	checkChobap.resize(D + 1);
	checkChobap[C] = true;

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	maxGazi = gaziCalculator(0);

	for (int i = 1; i < N; i++) {
		int gazisu = gaziCalculator(i);
		if (gazisu > maxGazi) {
			maxGazi = gazisu;
			maxLine = i;
		}
	}

	cout << maxGazi + 1;
}