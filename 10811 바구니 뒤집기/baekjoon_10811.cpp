#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> x(N);


	for (int i = 0; i < N; i++) {
		x[i] = i + 1;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1;
		b -= 1;
		int temp = x[a];
		x[a] = x[b];
		x[b] = temp;
	}

	for (int i = 0; i < N; i++) {
		cout << x[i] << ' ';
	}
}