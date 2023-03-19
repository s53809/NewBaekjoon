#include <iostream>
#include <string>
using namespace std;

void plusI(string &i) {
	int j = i.size() - 1;
	while (j >= 0) {
		if (i[j] == '9') {
			i[j] = '0';
		}
		else {
			i[j] = i[j] + 1;
			break;
		}
		j--;
	}
	if (j == -1) {
		i[0] = '1';
		i += '0';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	int hap = 0;
	bool isJJak = false;
	int ans = 0;
	while(true) {
		hap = 0;
		isJJak = false;
		for (int i = 0, a_size = a.size(); i < a_size; i++) {
			hap += a[i] - '0';
			if (a[i] == '3' || a[i] == '6' || a[i] == '9') {
				isJJak = true;
				break;
			}
		}
		if (hap % 3 == 0) isJJak = true;
		if (isJJak) {
			ans += 1;
			ans %= 20150523;
		}
		if (a != b) {
			plusI(a);
		}
		else {
			break;
		}
	}
	cout << ans;
}