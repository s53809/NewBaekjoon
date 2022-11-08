#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	x.push_back(1);
	x.push_back(1);
	x.push_back(1);
	for (int i = 3; i < N; i++) {
		x[i] = x[i - 1] + x[i - 3];
	}
	cout << x[N - 1];
}