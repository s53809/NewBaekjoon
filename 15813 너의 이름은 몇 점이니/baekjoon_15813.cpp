#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += str[i] - 'A' + 1;
	}
	cout << ans;
}