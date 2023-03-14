#include <iostream>
#include <string>
using namespace std;

int main() {
	int x[] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0, s_size = s.size(); i < s_size; i++) {
		ans += x[s[i] - 'A'];
	}
	cout << ans;
}