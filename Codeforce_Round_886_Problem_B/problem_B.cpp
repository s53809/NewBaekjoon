#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pair<int,int>> arr;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			if (a > 10) continue;
			arr.push_back({ b,i });
		}
		sort(arr.begin(), arr.end());
		cout << arr[arr.size() - 1].second + 1 << '\n';
	}
}