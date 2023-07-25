#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	while (N--) {
		vector<int> x(3);
		for (int i = 0; i < 3; i++) {
			cin >> x[i];
		}
		sort(x.begin(), x.end());
		if (x[1] + x[2] >= 10) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}