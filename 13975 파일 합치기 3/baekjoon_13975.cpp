#include <iostream>
#include <queue>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			ll input;
			cin >> input;
			pq.push(input);
		}
		
		ll ans = 0;
		while (pq.size() != 1) {
			ll temp_1 = pq.top(); pq.pop();
			ll temp_2 = pq.top(); pq.pop();
			
			ans += temp_1 + temp_2;
			pq.push(temp_1 + temp_2);
		}

		cout << ans << '\n';
	}
}