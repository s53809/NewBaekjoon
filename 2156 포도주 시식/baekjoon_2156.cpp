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
	vector<int> cur;
	vector<int> hap;
	vector<int> hap_max;
	cur.resize(N);
	hap.resize(N);
	hap_max.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> cur[i];
	}

	hap[0] = cur[0];
	if (N >= 2) hap[1] = hap[0] + cur[1];
	if (N >= 3) hap[2] = max(cur[1] + cur[2], cur[0] + cur[2]);
	hap_max[0] = hap[0];
	hap_max[1] = max(hap[0], hap[1]);
	hap_max[2] = max(hap_max[1], hap[2]);

	for (int i = 3; i < N; i++) {
		hap[i] = max(hap[i - 2] + cur[i], hap_max[i - 3] + cur[i - 1] + cur[i]);
		hap_max[i] = max(hap_max[i - 1], hap[i]);
	}

	int maximum = 0;

	for (int i = 0; i < N; i++) {
		//cout << hap[i] << ' ';
		maximum = max(maximum, hap[i]);
	}

	//cout << '\n';
	cout << maximum;
}