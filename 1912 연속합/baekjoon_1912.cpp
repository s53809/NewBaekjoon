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
	vector<int> x;
	vector<int> hap;

	cin >> N;
	x.resize(N);
	hap.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	hap[0] = x[0];

	for (int i = 1; i < N; i++) {
		hap[i] = max(x[i], hap[i - 1] + x[i]);
	}

	int maxNum = -1 * 2e9;

	for (int i = 0; i < N; i++) {
		maxNum = max(maxNum, hap[i]);
	}

	cout << maxNum;
}