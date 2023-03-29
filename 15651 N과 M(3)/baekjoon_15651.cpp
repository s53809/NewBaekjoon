#include <iostream>
#include <vector>
using namespace std;

void suYeoul(int N, int M, vector<int> &x) {
	if (M == 0) {
		for (int i = 0, x_size = x.size(); i < x_size; i++) {
			cout << x[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		x.push_back(i);
		suYeoul(N, M - 1, x);
		x.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> x;
	suYeoul(N, M, x);
}