#include <iostream>
#include <vector>
using namespace std;

long long N;
vector<long long> dari;
vector<long long> zuyu;
long long ans = 0;

void solve() {
	long long num = zuyu[0];
	for (int i = 0; i < N - 1; i++) {
		if (num > zuyu[i]) {
			num = zuyu[i];
		}
		ans += num * dari[i];
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dari.resize(N - 1);
	zuyu.resize(N);

	for (int i = 0, vecLength = dari.size(); i < vecLength; i++) {
		cin >> dari[i];
	}
	for (int i = 0, vecLength = zuyu.size(); i < vecLength; i++) {
		cin >> zuyu[i];
	}

	solve();
}