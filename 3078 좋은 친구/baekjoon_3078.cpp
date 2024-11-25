#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
typedef long long int lld;
using namespace std;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		x[i] = str.size();
	}

	queue<int> qu;
	int i = 0;

	int dic[21] = { 0 };

	for (i = 0; i < K + 1; i++) {
		qu.push(x[i]);
		dic[x[i]]++;
	}
	lld ans = 0;
	while (!qu.empty()) {
		int temp = qu.front();
		qu.pop();
		dic[temp]--;
		//cout << temp << ' ' << dic[temp] << '\n';
		if (dic[temp] >= 1) ans += dic[temp];
		if (i < N) { qu.push(x[i]); dic[x[i++]]++; }
	}
	cout << ans;
}