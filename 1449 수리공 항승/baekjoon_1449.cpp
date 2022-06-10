#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<int> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	sort(x.begin(), x.end());

	int ans = 1;
	int Eha = x[0] + L - 1;

	for (int i = 1; i < N; i++) {
		if (x[i] > Eha) {
			Eha = x[i] + L - 1;
			ans++;
		}
	}

	cout << ans;
}