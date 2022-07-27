#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
	
int N;
vector<int> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		vector<int> less;
		vector<int> high;
		for (int j = 0; j < i; j++) {
			if (less.empty()) {
				if (x[i] > x[j]) {
					less.push_back(x[j]);
				}
			}
			else if (x[i] > x[j] && (*(less.end() - 1)) < x[j]) {
				less.push_back(x[j]);
			}
			else if (x[i] > x[j] && !less.empty()) {
				vector<int>::iterator low;
				low = lower_bound(less.begin(), less.end(), x[j]);
				(*low) = x[j];
			}
		}

		for (int j = N - 1; j >= i + 1; j--) {
			if (high.empty()) {
				if (x[i] > x[j]) {
					high.push_back(x[j]);
				}
			}
			else if (x[i] > x[j] && (*(high.end() - 1)) < x[j]) {
				high.push_back(x[j]);
			}
			else if (x[i] > x[j] && !high.empty()) {
				vector<int>::iterator up;
				up = lower_bound(high.begin(), high.end(), x[j]);
				(*up) = x[j];
			}
		}
		/*cout << "x[" << i << "] (" << x[i] << "): " << less.size() << ' ' << high.size() << '\n';
		for (int j = 0, less_size = less.size(); j < less_size; j++) {
			cout << less[j] << ' ';
		}
		cout << " || ";
		for (int j = 0, high_size = high.size(); j < high_size; j++) {
			cout << high[j] << ' ';
		}
		cout << '\n';*/
		ans = max(ans, (int)(less.size() + high.size() + 1));
	}

	cout << ans;
}