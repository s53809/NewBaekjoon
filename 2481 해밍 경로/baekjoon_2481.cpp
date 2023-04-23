#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

int N, K, M;
vector<int> x;
map<int, int> pos;

int binaryTrans(string str) {
	int ans = 0;
	for (int i = 0, str_size = str.size(); i < str_size; i++) {
		ans += (str[i] - '0') * pow(2, str_size - i - 1);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> K;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		x[i] = binaryTrans(str);
		pos[x[i]] = i;
	}

	cin >> M;
	vector<vector<int>> graph(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int dir = x[i] ^ (1 << j);
			if (pos.find(dir) != pos.end()) {
				graph[i].push_back(pos[dir]);
			}
		}
	}

	queue<int> qu;
	qu.push(0);
	map<int, int> dic;
	dic[0] = -1;
	while (!qu.empty()) {
		int dir = qu.front();
		qu.pop();
		for (int var : graph[dir]) {
			if (dic.find(var) != dic.end()) continue;
			qu.push(var);
			dic[var] = dir;
		}
	}

	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		input--;
		if (dic.find(input) == dic.end()) { cout << "-1\n"; continue; }

		vector<int> ans;
		while (input != -1) {
			ans.push_back(input);
			input = dic[input];
		}

		for (int j = ans.size() - 1; j >= 0; j--) cout << ans[j] + 1 << ' ';
		cout << '\n';
	}
}