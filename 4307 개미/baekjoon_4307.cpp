#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int len, num;
		cin >> len >> num;
		int slow = 0, fast = 0;	
		for (int i = 0; i < num; i++) {
			int N;
			cin >> N;
			int ans_1 = min(N, len - N);
			int ans_2 = max(N, len - N);

			fast = max(fast, ans_1);
			slow = max(slow, ans_2);
		}
		cout << fast << ' ' << slow << '\n';
	}
}