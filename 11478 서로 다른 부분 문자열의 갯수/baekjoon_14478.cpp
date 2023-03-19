#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	set<string> x;

	for (int i = 0, str_size = str.size(); i < str_size; i++) {
		string temp = "";
		for (int j = i; j < str_size; j++) {
			temp += str[j];
			x.insert(temp);
		}
	}

	cout << x.size();
}