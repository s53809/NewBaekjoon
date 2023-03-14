#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	cout.precision(3);

	while (T--) {
		int N;
		cin >> N;
		vector<float> x(N);
		float hap = 0;
		for (int i = 0; i < N; i++) {
			cin >> x[i];
			hap += x[i];
		}
		float average = hap / N;
		float cnt = 0;

		for (int i = 0; i < N; i++) {
			if (average < x[i]) {
				cnt += 1;
			}
		}

		printf("%.3f", (cnt / N) * 100);
		cout << "%\n";
	}
}