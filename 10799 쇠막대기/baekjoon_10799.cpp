#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int str_size = str.size();
	stack<int> st;
	int ans = 0;
	for (int i = 0; i < str_size; i++) {
		if (str[i] == '(') {
			if (str[i + 1] != ')') {
				ans++;
			}
			st.push(1);
		}
		if (str[i] == ')') {
			if (str[i - 1] == '(') {
				st.pop();
				ans += st.size();
			}
			else {
				st.pop();
			}
		}
	}

	cout << ans;
}