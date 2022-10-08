#include <iostream>
#include <vector>
using namespace std;

int N, M;
int num;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	cin >> num;
	num++;
	vec.resize(num);

	int ZiksagakhyongDullae = (N + M) * 2;

	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			vec[i] = b;
		}
		else if (a == 2) {
			vec[i] = (ZiksagakhyongDullae - M) - b;
		}
		else if (a == 3) {
			vec[i] = ZiksagakhyongDullae - b;
		}
		else {
			vec[i] = N + b;
		}
	}
	int ans = 0;

	for (int i = 0; i < num - 1; i++) {
		int dir = abs((vec[num - 1]) - vec[i]);
		//cout << min((ZiksagakhyongDullae - dir), dir) << '\n';
		ans += min((ZiksagakhyongDullae - dir), dir);
	}

	cout << ans;
}