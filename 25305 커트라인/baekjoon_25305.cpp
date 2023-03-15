#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end(), [](int a, int b) {return a > b; });
	cout << x[M - 1];
}