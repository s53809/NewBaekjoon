#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> x;
vector<int> maximum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	x.resize(N);
	maximum.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		maximum[i] = 0;
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int box = x[i];
		maximum[i] = x[i];
		for (int j = 0; j < i; j++) {
			if (x[j] < x[i] && maximum[j] + box > maximum[i]) {
				maximum[i] = maximum[j] + box;
			}
		}
		ans = max(ans, maximum[i]);
	}

	cout << ans;
}
