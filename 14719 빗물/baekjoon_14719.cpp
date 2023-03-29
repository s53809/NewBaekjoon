#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int H, W;
	cin >> H >> W;
	if (W <= 2) { cout << "0\n"; return 0; }
	vector<int> x(W);
	for (int i = 0; i < W; i++) {
		cin >> x[i];
	}
	int ans = 0;
	for (int i = 1; i <= H; i++) {
		stack<int> st;
		bool isStart = false;
		for (int j = 0; j < W; j++) {
			if (i <= x[j]) isStart = true;
			if (!isStart) continue;
			if (i <= x[j] && !st.empty()) {
				while (!st.empty()) { ans += st.top(); st.pop(); }
			}
			else if (i > x[j]) st.push(1);
		}
	}

	cout << ans;
}