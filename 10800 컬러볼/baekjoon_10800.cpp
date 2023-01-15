#include <iostream>
#include <vector>
#include <algorithm>
#define lld long long int
using namespace std;

struct Ball {
	lld color;
	lld size;
	lld defaultNum;
};

int N;
vector<Ball> x;
vector<lld> c(200001, 0);
vector<lld> old_c(200001, 0);
vector<int> ans;
lld total = 0;
lld old_total = 0;
lld maxColor = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	ans.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i].color >> x[i].size;
		x[i].defaultNum = i;
		maxColor = max(maxColor, x[i].color);
	}
	sort(x.begin(), x.end(), [](const Ball &a, const Ball &b) { 
		if (a.size != b.size) { return a.size < b.size; }
		else { return a.color < b.color; }
	});

	bool isOld = false;

	for (int i = 0; i < N; i++) {
		if (!isOld && i != 0 && x[i - 1].size == x[i].size) {
			isOld = true;
			old_total = total - x[i - 1].size;
			for (int j = 0; j <= maxColor; j++) {
				old_c[j] = c[j];
			}
			old_c[x[i - 1].color] = c[x[i - 1].color] - x[i - 1].size;
		}
		
		if (isOld && x[i - 1].size != x[i].size) { isOld = false; }
		else if (isOld && x[i - 1].size == x[i].size) { ans[x[i].defaultNum] += old_total - old_c[x[i].color]; }
		
		if(!isOld) { ans[x[i].defaultNum] += total - c[x[i].color]; }
		
		total += x[i].size;
		c[x[i].color] += x[i].size;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << '\n';
	}
}