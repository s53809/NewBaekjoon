#include <iostream>
#include <queue>
#include <algorithm>
#define lld long long int
using namespace std;

lld mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N;
		priority_queue<lld, vector<lld>, greater<lld>> pq;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			pq.push(a);
		}

		lld ans = 1;

		while (pq.size() > 1) {
			lld temp = pq.top(); pq.pop();
			lld temp_1 = pq.top(); pq.pop();

			ans = ans * ((temp * temp_1) % mod) % mod;
			pq.push(temp * temp_1);
		}

		cout << ans << '\n';
	}
}