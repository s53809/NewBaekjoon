#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> arr(N, vector<int>(M));
	vector<vector<int>> ans(N, vector<int>(M, -1));

	pair<int, int> strPos;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) strPos = { j,i };
		}
	}

	queue<pair<int, int>> qu;
	qu.push(strPos);
	ans[strPos.second][strPos.first] = 0;
	
	while (!qu.empty()) {
		pair<int, int> dist = qu.front();
		qu.pop();
		
		for (int i = 0; i < 4; i++) {
			int dir_x = dist.first + d_x[i];
			int dir_y = dist.second + d_y[i];
			if (0 <= dir_x && dir_x < M && 0 <= dir_y && dir_y < N) {
				if (arr[dir_y][dir_x] == 1 && (ans[dir_y][dir_x] == -1 || ans[dir_y][dir_x] > ans[dist.second][dist.first] + 1)) {
					ans[dir_y][dir_x] = ans[dist.second][dist.first] + 1;
					qu.push({ dir_x, dir_y });
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 1) cout << "0 ";
			else if (ans[i][j] == 0) cout << "-1 ";
			else cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}