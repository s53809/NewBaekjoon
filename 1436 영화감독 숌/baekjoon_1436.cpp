#include <iostream>
using namespace std;

string arr = "0000000000";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int ans = 0;
	while (ans != N) {
		int i = 8;
		while (arr[i] == '9') {
			arr[i--] = '0';
		}
		arr[i]++;
		if (arr.find("666") == string::npos) {
			continue;
		}
		ans++;
	}
	int i = 0;
	while (arr[i] == '0') {
		i++;
	}
	
	while (i != 9) {
		cout << arr[i++];
	}
}