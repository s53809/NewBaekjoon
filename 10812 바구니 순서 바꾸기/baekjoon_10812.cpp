#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> x;

void swap(int a, int b, int c) {
	vector<int> temp;

	for (int i = c; i <= b; i++) {
		temp.push_back(x[i]);
	}
	for (int i = a; i < c; i++) {
		temp.push_back(x[i]);
	}

	int cnt = 0;
	for (int i = a; i <= b; i++) {
		x[i] = temp[cnt++];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		x[i] = i + 1;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		swap(a - 1, b - 1, c - 1);
	}

	for (int i = 0; i < N; i++) {
		cout << x[i] << ' ';
	}
}