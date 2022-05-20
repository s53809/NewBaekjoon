#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	queue<int> qu;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			qu.push(num);
		}
		if (str == "front") {
			if (qu.empty()) cout << "-1\n";
			else {
				cout << qu.front() << '\n';
			}
		}
		if (str == "pop") {
			if (qu.empty()) cout << "-1\n";
			else {
				cout << qu.front() << '\n';
				qu.pop();
			}
		}
		if (str == "size") {
			cout << qu.size() << '\n';
		}
		if (str == "empty") {
			if (qu.empty()) cout << "1\n";
			else cout << "0\n";
		}
		if (str == "back") {
			if (qu.empty()) cout << "-1\n";
			else {
				cout << qu.back() << '\n';
			}
		}
	}
}