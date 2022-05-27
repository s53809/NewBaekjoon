#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> x;
vector<int> erates;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	erates.resize(N + 1);
	fill(erates.begin(), erates.end(), 0);

	for (int i = 2; i <= sqrt(N); i++) {
		for (int j = 2 * i; j <= N; j += i) {
			erates[j] = -1;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (erates[i] != -1) {
			x.push_back(i);
		}
	}
	if (N == 1) {
		cout << 0;
		return 0;
	}
	int sum = x[0];
	int p1 = 0;
	int p2 = 0;
	int x_size = x.size();
	int ans = 0;
	while (p1 < x_size) {
		if (sum == N) {
			ans++;
			sum -= x[p1++];
		}
		else if (sum < N) {
			if (p2 == x_size - 1) {
				sum -= x[p1++];
			}
			else sum += x[++p2];
		}
		else {
			sum -= x[p1++];
		}
	}
	cout << ans;
}