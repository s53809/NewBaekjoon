#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> x(N);

	for (int i = 0; i < 10; i++) {
		cin >> x[i];
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (x[i] == N) {
			cout << "answer is " << i << '\n';
			break;
		}
	}
}