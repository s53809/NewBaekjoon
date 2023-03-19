#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int zzaksu = 0;
		int holsu = 0;
		bool isAns = true;
		vector<int> x;
		vector<int> y;
		for (int i = 1; i <= N; i++) {
			int num;
			cin >> num;
			if (num % 2 == 0) x.push_back(num);
			else y.push_back(num);
		}
		sort(x.begin(), x.end(), [](int a, int b) {return a > b; });
		sort(y.begin(), y.end());
		for (int i = 0, x_size = x.size(), y_size = y.size(); (i < x_size) || (i < y_size); i++) {
			if (i < x_size) zzaksu += x[i];
			if (i < y_size) holsu += y[i];
			if (zzaksu <= holsu) {
				isAns = false;
			}
		}
		if (isAns) cout << "YES\n";
		else cout << "NO\n";
	}
}