#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int uClid(int a, int b) {
	if (!b) return a;
	else return uClid(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> x(N);
	vector<int> dist;

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	for (int i = 0; i < N - 1; i++) {
		dist.push_back(x[i + 1] - x[i]);
	}

	int gcd = dist[0];

	for (int i = 1; i < N - 1; i++) {
		gcd = uClid(gcd, dist[i]);
	}

	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		cnt += dist[i] / gcd - 1;
	}
	cout << cnt;
}