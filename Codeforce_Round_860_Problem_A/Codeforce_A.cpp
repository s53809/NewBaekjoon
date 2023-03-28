#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> a(N);
		vector<int> b(N);
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> b[i];
		}
		bool isCorrect = true;
		for (int i = N - 2; i >= 0; i--) {
			if (a[N - 1] < a[i] || b[N - 1] < b[i]) {
				int temp = a[i];
				a[i] = b[i];
				b[i] = temp;

				if (a[N - 1] < a[i] || b[N - 1] < b[i]) {
					isCorrect = false;
					break;
				}
			}
		}
		if (isCorrect) { cout << "YES\n"; }
		else { cout << "NO\n"; }
	}
}