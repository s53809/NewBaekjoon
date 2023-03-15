#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int x[10001] = { 0 };
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		x[a]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < x[i]; j++) {
			cout << i << '\n';
		}
	}
}