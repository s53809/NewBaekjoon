#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		int box = 1;

		for (int i = 0; i < N; i++)
		{
			box *= M - i;
			box /= 1 + i;
		}

		cout << box << '\n';
	}
}