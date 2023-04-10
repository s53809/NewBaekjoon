#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	int ans = 0;

	while (!(pq.size() == 1)) {
		int temp_1 = pq.top(); pq.pop();
		int temp_2 = pq.top(); pq.pop();

		int box = temp_1 + temp_2;
		ans += box;
		pq.push(box);
	}

	cout << ans;
}