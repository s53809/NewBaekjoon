#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> x;
int N, M;
int K;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	cin >> K;
	map<string, int> dic;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < M; j++) if (x[i][j] == '0') cnt++;
		if (cnt > K || (cnt % 2 != K % 2)) continue;
		if (dic.find(x[i]) == dic.end()) dic.insert({ x[i], 1 });
		else dic[x[i]]++;
	}
	int ans = 0;
	for (pair<string, int> x : dic) {
		ans = max(ans, x.second);
	}
	cout << ans;
}