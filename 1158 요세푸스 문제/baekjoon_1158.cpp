#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	queue<int> qu;

	for (int i = 1; i <= N; i++) {
		qu.push(i);
	}

	cout << "<";
	for (int i = 0; i < N; i++) {
		for (int i = 1; i < K; i++) {
			int temp = qu.front();
			qu.pop();
			qu.push(temp);
		}
		cout << qu.front();
		if (i != N - 1) {
			cout << ", ";
		}
		qu.pop();
	}
	cout << ">";
}