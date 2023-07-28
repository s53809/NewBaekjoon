#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define div 1000000000
typedef long long int ll;
typedef vector<ll> vll;

int N;
vector<vector<vll>> dp;

int Count(int n) {
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		if ((n & (1 << i)) != 0) cnt++;
	}
	return cnt;
}

ll DP(int num, int visited, int stac) {
	ll& ret = dp[num][visited][stac];
	if (ret != 0) { return ret; }
	int cnt = Count(visited);
	if (N - stac > N - cnt) return 0;
	if (stac == N && cnt == 10) return 1;
	if (stac >= N && cnt != 10) return 0;
	ll hap = 0;
	if (num != 9) hap = (hap + DP(num + 1, visited | (1 << (num + 1)), stac + 1)) % div;
	if (num != 0) hap = (hap + DP(num - 1, visited | (1 << (num - 1)), stac + 1)) % div;
	return ret = hap;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;

	dp.resize(10, vector<vll>((1 << 10), vll(N + 1, 0)));

	ll ans = 0;
	for (int i = 1; i <= 9; i++) {
		//cout << i << ' ';
		ans = (ans + DP(i, (1 << i), 1)) % div;
		//cout << ans << '\n';
	}
	cout << ans;
}