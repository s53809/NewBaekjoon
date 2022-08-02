#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		qu.push(i);
	}

	for (int i = 0; i < N - 1; i++) {
		qu.pop();
		int temp = qu.front();
		qu.pop();
		qu.push(temp);
	}

	cout << qu.front();
}