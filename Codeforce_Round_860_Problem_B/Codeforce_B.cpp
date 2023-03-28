#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<vector<int>> x(N);
		set<int> dic;
		vector<int> ans;
		for (int i = 0; i < N; i++) {
			int partN;
			cin >> partN;
			for (int j = 0; j < partN; j++) {
				int num;
				cin >> num;
				x[i].push_back(num);
			}
		}

		for (int i = N - 1; i >= 0; i--) {
			bool findAns = false;
			for (int j = 0, x_size = x[i].size(); j < x_size; j++) {
				if (dic.find(x[i][j]) == dic.end()) {
					dic.insert(x[i][j]);
					if (findAns) continue;
					findAns = true;
					ans.push_back(x[i][j]);
				}
			}
		}

		if (ans.size() != N) {
			cout << "-1\n";
		}
		else {
			for (int i = ans.size() - 1; i >= 0; i--) {
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
	}
}