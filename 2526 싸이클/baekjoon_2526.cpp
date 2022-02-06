#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	vector<int> x;

	cin >> N >> M;

	x.push_back(N);
	int n = 1;
	while (true) {
		x.push_back(x[n - 1] * N % M);
		for (int i = 0; i < n; i++) {
			if (x[i] == x[n]) {
				cout << n - i;
				return 0;
			}
		}
		n++;
	}
}