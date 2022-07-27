#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		map<string, int> x;
		int N;
		int ans = 1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			pair<string, string> box;
			cin >> box.first >> box.second;
			if (x.find(box.second) == x.end()) {
				x.insert(make_pair(box.second, 1));
			}
			else {
				x[box.second]++;
			}
		}

		for (auto& box : x) {
			box.second++;
			ans *= box.second;
		}
		
		cout << ans - 1 << '\n';
	}
}