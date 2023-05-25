#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= (N - i); j++) {
			cout << ' ';
		}
		for (int j = (N - i) + 1; j <= N; j++) {
			cout << j;
		}
		cout << '\n';
	}
}