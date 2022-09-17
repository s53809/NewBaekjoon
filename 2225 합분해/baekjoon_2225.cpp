#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<long long>> arr;

long long sum(int n, int k) {
	if (k == 1) {
		return 1;
	}
	if (arr[n][k] != -1) {
		return arr[n][k];
	}
	long long hap = 0;
	for (int i = 0; i <= n; i++) {
		hap = (hap + sum(n - i, k - 1)) % 1000000000;
	}
	arr[n][k] = hap;
	return hap;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	arr.resize(N + 1, vector<long long>(K + 1, -1));

	cout << sum(N, K) % 1000000000;
}