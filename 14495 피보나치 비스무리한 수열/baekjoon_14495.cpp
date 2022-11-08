#include <iostream>
#include <vector>
#define lld long long int
using namespace std;

int N;
vector<lld> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	x.resize(116);
	x[0] = 1;
	x[1] = 1;
	x[2] = 1;
	for (int i = 3; i < N; i++) {
		x[i] = x[i - 1] + x[i - 3];
	}
	cout << x[N - 1];
}