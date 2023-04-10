#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	string str;

	cin >> N >> str;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'u' || str[i] == 'o') {
			ans++;
		}
	}

	cout << ans;
}