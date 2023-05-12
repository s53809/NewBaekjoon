#include <iostream>
#include <vector>
#include <algorithm>
#define lld long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> x(N);

	int Zaksu = 0;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	lld cntR = 0, cntL = 0;
	for (int i = 0; i < N; i++) {
		if (x[i] % 2 == 0) { 
			cntL += i - Zaksu;
			Zaksu++;
		}
	}

	Zaksu = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (x[i] % 2 == 0) {
			cntR += (N - 1 - i) - Zaksu;
			Zaksu++;
		}
	}

	cout << min(cntR, cntL);
}