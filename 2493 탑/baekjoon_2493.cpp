#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	vector<int> x;

	cin >> N;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	stack<pair<int, int>> st;
	st.push(make_pair(x[0], 1));
	cout << "0 ";

	for (int i = 1; i < N; i++) {
		while (!st.empty() && st.top().first < x[i]) {
			st.pop();
		}
		if (st.empty()) {
			cout << "0 ";
		}
		else {
			cout << st.top().second << " ";
		}
		st.push(make_pair(x[i], i + 1));
	}
	/*
	5
	6 9 5 7 4
	*/
}