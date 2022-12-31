#include <iostream>
#include <stack>
using namespace std;

string s;
stack<int> st;
int temp = 1;
int ans = 0;
bool isCorrect = true;

void Gomsa(char i) {
	if (s[i] == '(') {
		st.push(1);
		temp *= 2;
	}
	else if (s[i] == '[') {
		st.push(2);
		temp *= 3;
	}
	else if (s[i] == ']') {
		if (st.empty() || st.top() != 2) {
			isCorrect = false;
		}
		else if (s[i - 1] == '[') {
			ans += temp;
			temp /= 3;
			st.pop();
		}
		else {
			temp /= 3;
			st.pop();
		}
	}
	else if (s[i] == ')') {
		if (st.empty() || st.top() != 1) {
			isCorrect = false;
		}
		else if (s[i - 1] == '(') {
			ans += temp;
			temp /= 2;
			st.pop();
		}
		else {
			temp /= 2;
			st.pop();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		Gomsa(i);
		if (!isCorrect) {
			break;
		}
	}
	if (!isCorrect || !st.empty()) {
		cout << "0";
		return 0;
	}
	cout << ans;
}