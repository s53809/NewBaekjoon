#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		stack<int> st;
		bool isAns = true;
		string str;
		cin >> str;
		for (int i = 0, strSize = str.size(); i < strSize; i++) {
			if (str[i] == '(') {
				st.push(0);
			}
			else {
				if (st.empty()) {
					isAns = false;
					break;
				}
				else st.pop();
			}
		}
		if (!st.empty()) isAns = false;
		if (isAns) cout << "YES\n";
		else cout << "NO\n";
	}
}