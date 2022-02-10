#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int N;
vector<vector<pair<int, bool>>> x;
int d_x[] = { -1,1,0,0 };
int d_y[] = { 0,0,-1,1 };

int BFS(int posX,int posY) {
	x[posY][posX].second = true;
	queue<pair<int,int>> qu;
	qu.push(make_pair(posX, posY));
	int getsu = 1;
	while (!qu.empty()) {
		pair<int, int> dist = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int dir_x = dist.first + d_x[i];
			int dir_y = dist.second + d_y[i];
			if (dir_x >= 0 && dir_x < N && dir_y >= 0 && dir_y < N) {
				if (x[dir_y][dir_x].first != 0 && x[dir_y][dir_x].second == false) {
					qu.push(make_pair(dir_x, dir_y));
					x[dir_y][dir_x].second = true;
					getsu++;
				}
			}
		}
	}
	return getsu;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	
	for (int i = 0; i < N; i++) {
		x[i].resize(N);
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			x[i][j].first = str[j] - '0';
			x[i][j].second = false;
		}
	}

	vector<int> sortX;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (x[i][j].first == 1 && x[i][j].second == false) {
				sortX.push_back(BFS(j, i));
			}
		}
	}

	sort(sortX.begin(), sortX.end());
	int length = sortX.size();
	cout << length << '\n';
	for (int i = 0; i < length; i++) {
		cout << sortX[i] << '\n';
	}

}