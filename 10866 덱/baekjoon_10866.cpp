#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string str;
	deque<int> x;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push_front") {
			int temp;
			cin >> temp;
			x.push_front(temp);
		}
		else if (str == "push_back") {
			int temp;
			cin >> temp;
			x.push_back(temp);
		}
		else if (str == "pop_front") {
			if (x.empty()) {
				cout << "-1\n";
			}
			else {
				cout << x.front() << '\n';
				x.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (x.empty()) {
				cout << "-1\n";
			}
			else {
				cout << x.back() << '\n';
				x.pop_back();
			}
		}
		else if (str == "size") {
			cout << x.size() << '\n';
		}
		else if (str == "empty") {
			if (x.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (str == "front") {
			if (x.empty()) {
				cout << "-1\n";
			}
			else {
				cout << x.front() << '\n';
			}
		}
		else if (str == "back") {
			if (x.empty()) {
				cout << "-1\n";
			}
			else {
				cout << x.back() << '\n';
			}
		}
		else {
			cout << "ERROR\n";
		}
	}
}