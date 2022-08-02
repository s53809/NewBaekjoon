#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> x;
	vector<string> answer;
	stack<int> st;
	int prev = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		x.push_back(num);
	}
	int box = 1;
	bool isAnim = false;
	st.push(box++);
	answer.push_back("+");
	for (int i = 0; i < N; i++) {
		if (!st.empty() && st.top() != x[i] && x[i] < st.top()) {
			isAnim = true;
			break;
		}
		if (st.empty()) {
			st.push(box++);
			answer.push_back("+");
		}
		while (st.top() != x[i]) {
			st.push(box++);
			answer.push_back("+");
		}
		st.pop();
		answer.push_back("-");
	}
	if (isAnim) {
		cout << "NO\n";
	}
	else {
		for (int i = 0, answer_size = answer.size(); i < answer_size; i++) {
			cout << answer[i] << '\n';
		}
	}
}