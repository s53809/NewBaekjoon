#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> x(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	int M;
	cin >> M;
	vector<int> y(M);

	for (int i = 0; i < M; i++) {
		cin >> y[i];
	}

	sort(x.begin(), x.end());
	
	for (int i = 0; i < M; i++) {
		if (binary_search(x.begin(), x.end(), y[i])) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}
}