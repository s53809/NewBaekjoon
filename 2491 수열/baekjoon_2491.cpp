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
	x.resize(N);
	
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	int maximum = 1;

	stack<int> st;
	st.push(x[0]);
	for (int i = 1; i < N; i++) { // 연속해서 커지는 것 검사
		
 		if (st.top() <= x[i]) {
			st.push(x[i]);
		}
		else {
			if (maximum < st.size()) {
				maximum = st.size();
			}
			while (!st.empty()) {
				st.pop();
			}
			st.push(x[i]);
		}
		if (maximum < st.size()) {
			maximum = st.size();
		}
	}
	while (!st.empty()) {
		st.pop();
	}
	st.push(x[0]);
	for (int i = 1; i < N; i++) { // 연속해서 작아지는 것 검사
		
		if (st.top() >= x[i]) {
			st.push(x[i]);
		}
		else {
			while (!st.empty()) {
				st.pop();
			}
			st.push(x[i]);
		}
		if (maximum < st.size()) {
			maximum = st.size();
		}
	}
	cout << maximum;
}