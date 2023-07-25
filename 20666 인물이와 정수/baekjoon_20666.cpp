#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
priority_queue<pll, vector<pll>, greater<pll>> pq;

int N, M;
vector<ll> tip(100001);
int P;
vector<vector<pll>> item(100001);
vector<bool> visited(100001, false);


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> tip[i];
	}
	cin >> P;
	for (int i = 0; i < P; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tip[b] += c;
		item[a].push_back({ b,c });
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		pq.push({ tip[i], i });
	}

	ll ans = 0;

	while (cnt < M) {
		pll monster = pq.top();
		pq.pop();
		if (visited[monster.second]) continue;
		visited[monster.second] = true;
		for (pll temp : item[monster.second]) {
			if (visited[temp.first]) continue;
			tip[temp.first] -= temp.second;
			pq.push({ tip[temp.first], temp.first });
		}

		ans = max(ans, monster.first);
		cnt++;
	}
	cout << ans;
}