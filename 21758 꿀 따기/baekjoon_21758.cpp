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
	x.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}


}