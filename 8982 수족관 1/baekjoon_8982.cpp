#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<pair<int, int>> x;
vector<pair<int, int>> hole;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;

	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
	}

	cin >> K;
	
	hole.resize(K * 2 + 3);
	
	hole[0] = { 0,0 };
	hole[K * 2 + 1] = { x[N - 1].first, x[N - 1].second };
	hole[K * 2 + 2] = { x[N - 1].first, x[N - 1].second };
	for (int i = 1; i <= K * 2; i++) {
		cin >> hole[i].first >> hole[i].second;
	}

	int holeIndex = 1;
	int holeHeight = hole[0].second;
	int ans = 0;
	for (int i = 2; i < N - 1; i += 2) {
		cout << x[i - 1].first << ' ' << x[i - 1].second << ' ' << x[i].first << ' ' << x[i].second;
		if (x[i] == hole[holeIndex + 1]) {
			cout << "is first if\n";
			holeIndex += 2;
			holeHeight = hole[holeIndex - 1].second;
		}
		else {
			cout << "is second if ";
			int height = (x[i].second - max(holeHeight, x[i + 1].second));
			cout << height << '\n';
			if (height < 0) {
				holeHeight = x[i].second;
				height = 0;
			}
			cout << "TEST: " << height << ' ' << (x[i].first - x[i - 1].first) << ' ' << height * (x[i].first - x[i - 1].first) << '\n';
			ans += height * (x[i].first - x[i - 1].first);
		}
	}

	cout << ans;
}