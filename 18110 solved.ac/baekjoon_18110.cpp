#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	if (N == 0) { cout << "0"; return 0; }
	int musiValue = round((float)N * 0.15);
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());

	int hap = 0;
	for (int i = musiValue; i < N - musiValue; i++) {
		hap += x[i];
	}

	cout << round((float)hap / (N - (musiValue * 2)));
}