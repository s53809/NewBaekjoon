#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> x;

int DP(int N) {
	if (N >= 1 && N <= 3) return x[N];
	if (x[N] == 0) return x[N] = DP(N - 1) + DP(N - 3);
	else return x[N];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	x.resize(N);
	fill(x.begin(), x.end(), 0);
	x[0] = 1;
	x[1] = 1;
	x[2] = 1;
	cout << DP(N - 1) << '\n';
	for (int i = 0, vecLength = x.size(); i < vecLength; i++) {
		cout << x[i] << ' ';
	}
}