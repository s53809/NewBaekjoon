#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> x;
vector<int> hap;
vector<int> reverseHap;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	hap.resize(N);
	reverseHap.resize(N);


	for (int i = 0; i < N; i++) {
		cin >> x[i];
		if (i != 0) hap[i] = hap[i - 1] + x[i];
		else hap[i] = x[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (i != N - 1) { reverseHap[i] = reverseHap[i + 1] + x[i]; }
		else reverseHap[i] = x[i];
	}

	int maxHap = 0; // 国国曹
	for (int i = 1; i < N - 1; i++) {
		maxHap = max((hap[N - 1] - x[i] - hap[0]) + (hap[N - 1] - hap[i]), maxHap);
	}

	//国曹国
	for (int i = 1; i < N - 1; i++) {
		maxHap = max((hap[i] - hap[0]) + (reverseHap[i] - reverseHap[N - 1]), maxHap);
	}

	//曹国国
	for (int i = 1; i < N - 1; i++) {
		maxHap = max((reverseHap[0] - x[i] - reverseHap[N - 1]) + (reverseHap[0] - reverseHap[i]), maxHap);
	}

	cout << maxHap;
}