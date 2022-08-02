#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	stack<int> st;
	for (int i = 0; i < N; i++) {
		int box;
		cin >> box;
		if (box != 0) {
			st.push(box);
		}
		else {
			st.pop();
		}
	}

	int ans = 0;
	for (int i = 0, st_size = st.size(); i < st_size; i++) {
		ans += st.top();
		st.pop();
	}
	cout << ans;
}