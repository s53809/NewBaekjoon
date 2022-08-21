#include <iostream>
using namespace std;
int hap[1001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	hap[0] = 1;
	hap[1] = 3;

	for (int i = 2; i < N; i++) {
		hap[i] = (hap[i-1] + hap[i-2] + hap[i-2]) % 10007;
	}



	cout << hap[N - 1];
}