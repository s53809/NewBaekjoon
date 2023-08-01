#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;

int T;
int N, M;
vector<int> x, y;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> T;

	cin >> N;
	x.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		x[i] = x[i - 1] + a;
	}

	cin >> M;
	y.resize(M + 1, 0);
	for (int i = 1; i <= M; i++) {
		int a;
		cin >> a;
		y[i] = y[i - 1] + a;
	}

	map<int, ll> dic;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (dic.find(x[j] - x[i]) != dic.end()) {
				dic[x[j] - x[i]]++;
			}
			else {
				dic.insert({ x[j] - x[i], 1 });
			}
		}
	}

	ll ans = 0;

	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j <= M; j++) {
			int value = y[j] - y[i];
			//cout << "TEST: " << j << ' ' << i << ' ' << value << '\n';
			if (dic.find(T - value) != dic.end()) {
				ans += dic[T - value];
			}
		}
	}
	cout << ans;
}