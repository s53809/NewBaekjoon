#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	x.insert({ "black", 0});
	x.insert({ "brown", 1 });
	x.insert({ "red", 2 });
	x.insert({ "orange", 3 });
	x.insert({ "yellow", 4 });
	x.insert({ "green", 5 });
	x.insert({ "blue", 6 });
	x.insert({ "violet", 7 });
	x.insert({ "grey", 8 });
	x.insert({ "white", 9 });
	int ans = 0;
	string str;
	cin >> str;
	ans = x[str] * 10;
	cin >> str;
	ans += x[str];
	cin >> str;
	cout << ans;
	if (ans == 0) return 0;
	for (int i = 0; i < x[str]; i++) {
		cout << "0";
	}
}