#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> x(N + 1);
	fill(x.begin(), x.end(), 0);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j <= b; j++) {
			x[j] = c;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << x[i] << ' ';
	}
}