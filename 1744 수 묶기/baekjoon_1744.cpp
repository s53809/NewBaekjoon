#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	sort(x.begin(), x.end(), [](int a, int b) { return a > b; });

	int ans = 0;
	int i = 0;
	for (i = 0; i < N; i++) {
		if (i != N - 1 && x[i] > 0 && x[i + 1] > 0 && x[i] != 1 && x[i + 1] != 1) {
			ans += (x[i] * x[i + 1]);
			i++;
		}
		else if (x[i] > 0) {
			ans += x[i];
		}
		else {
			break;
		}
	}

	for (int j = N - 1; j >= i; j--) {
		if (j != i) {
			ans += (x[j] * x[j - 1]);
			j--;
		}
		else {
			ans += x[j];
		}
	}

	cout << ans;
}