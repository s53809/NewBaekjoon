#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

list<char> x;

void print() {
	list<char>::iterator it = x.begin();
	for (it = x.begin(); it != x.end(); it++) {
		if (it == x.begin()) {
			it++;
		}
		cout << *it;
	}

	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	string str;

	cin >> str;
	cin >> N;

	x.push_back('X');
	for (int i = 0, str_size = str.size(); i < str_size; i++) {
		x.push_back(str[i]);
	}

	list<char>::iterator it = x.end();
	it--;

	while (N--) {
		char ch;
		cin >> ch;

		if (ch == 'P') {
			char box;
			cin >> box;
			it++;
			if (it == x.end()) {
				x.push_back(box);
				it--;
			}
			else {
				x.insert(it, box);
				it--;
			}
		}
		if (ch == 'L') {
			if (it != x.begin()) {
				it--;
			}
		}
		if (ch == 'D') {
			if (++it == x.end()) {
				it--;
			}
		}
		if (ch == 'B') {
			if (it != x.begin()) {
				auto itTemp = it--;
				x.erase(itTemp);
			}
		}
// 		cout << *it << ": ";
// 		print();
	}
	print();
}