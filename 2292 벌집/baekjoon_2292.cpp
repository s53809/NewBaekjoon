#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	int stac = 1;
	int num_1 = 0;
	int num = 1;
	if (N == 1) { cout << 1; return 0; }
	while (true) {
		num_1 += 6;
		num += num_1;
		stac++;
		if (N <= num) { cout << stac; break; }
	}
}