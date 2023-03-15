#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int N;
		cin >> N;
		if (N == -1) break;
		int hap = 0;
		vector<int> yoso;
		for (int i = 1; i <= N / 2; i++) {
			if (N % i == 0) { yoso.push_back(i); hap += i; }
		}
		if (hap == N) {
			cout << N << " = ";
			for (int i = 0, yoso_size = yoso.size(); i < yoso_size; i++) {
				cout << yoso[i];
				if (i != yoso_size - 1) cout << " + ";
			}
			cout << '\n';
		}
		else {
			cout << N << " is NOT perfect.\n";
		}
	}
}