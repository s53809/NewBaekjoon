#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> x(N);
	int getsu[8001] = { 0 };

	int hap = 0;

	for (int i = 0; i < N; i++) {
		cin >> x[i];
		getsu[x[i] + 4000]++;
		hap += x[i];
	}

	sort(x.begin(), x.end());

	hap = round((float)hap / N);

	cout << hap << '\n' << x[N / 2] << '\n';
	int maxNum = 0;
	bool twelve = false;

	for (int i = 1; i < 8001; i++) {
		if (getsu[maxNum] == getsu[i]) {
			if (!twelve) {
				maxNum = i;
				twelve = true;
			}
		}
		if (getsu[maxNum] < getsu[i]) {
			maxNum = i;
			twelve = false;
		}
	}
	cout << maxNum - 4000 << '\n';
	cout << x.back() - x.front() << '\n';
}