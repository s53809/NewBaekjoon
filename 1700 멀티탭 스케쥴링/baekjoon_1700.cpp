#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, K;
	int x[101];
	vector<queue<int>> dir(101, queue<int>());

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> x[i];
		dir[x[i]].push(i);
	}
	
	vector<int> multiTap;
	int ans = 0;
	for (int i = 0; i < K; i++) {
		bool isContinue = false;
		for (int j = 0; j < multiTap.size(); j++) {
			if (x[i] == multiTap[j]) { 
				dir[multiTap[j]].pop(); 
				isContinue = true;
				break; 
			}
		}
		if (isContinue) continue;
		if (multiTap.size() < N) {
			multiTap.push_back(x[i]);
			dir[x[i]].pop();
		}
		else {
			pair<int, int> temp = { 0,0 };
			ans++;
			bool isBreak = false;
			for (int j = 0; j < N; j++) {
				if (dir[multiTap[j]].empty()) { 
					multiTap.erase(multiTap.begin() + j); 
					multiTap.push_back(x[i]);
					dir[x[i]].pop();
					isBreak = true;
					break; 
				}
				else if (dir[multiTap[j]].front() > temp.second) {
					temp.first = j;
					temp.second = dir[multiTap[j]].front();
				}
			}
			if (isBreak) continue;
			multiTap.erase(multiTap.begin() + temp.first);
			multiTap.push_back(x[i]);
			dir[x[i]].pop();
		}
	}

	cout << ans;
}