#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, T, K;
vector<pair<int, int>> dot;
vector<bool> xZonzae;
vector<bool> yZonzae;
vector<int> xPos;
vector<int> yPos;

pair<int, int> Tamsek(int x, int y) {
	int d_x[] = { K,K * -1,K,K * -1 }; //오른쪽 위, 왼쪽 위, 오른쪽 아래, 왼쪽 아래
	int d_y[] = { K,K,K * -1,K * -1 };
	int ans = -1;
	int vec = -1;

	for (int u = 0; u < 4; u++) {
		int dir_x = x + d_x[u];
		int dir_y = y + d_y[u];
		int temp = 0;
		if (dir_x >= 0 && dir_x <= N && dir_y >= 0 && dir_y <= M) {
			for (int i = 0; i < T; i++) {
				if (u == 0) {
					if (dot[i].first >= x && dot[i].first <= dir_x && dot[i].second >= y && dot[i].second <= dir_y) {
						temp++;
					}
				}
				else if (u == 1) {
					if (dot[i].first <= x && dot[i].first >= dir_x && dot[i].second >= y && dot[i].second <= dir_y) {
						temp++;
					}
				}
				else if (u == 2) {
					if (dot[i].first >= x && dot[i].first <= dir_x && dot[i].second <= y && dot[i].second >= dir_y) {
						temp++;
					}
				}
				else if (u == 3) {
					if (dot[i].first <= x && dot[i].first >= dir_x && dot[i].second <= y && dot[i].second >= dir_y) {
						temp++;
					}
				}
			}
		}
		if (ans < temp) {
			ans = temp;
			vec = u;
		}
	}

	return make_pair(ans, vec);
}

pair<int, int> leftUp(int x, int y, int vec) {
	int d_x[] = { K,K * -1,K,K * -1 }; //오른쪽 위, 왼쪽 위, 오른쪽 아래, 왼쪽 아래
	int d_y[] = { K,K,K * -1,K * -1 };

	if (vec == 0) {
		return make_pair(x, y + K);
	}
	else if (vec == 1) {
		return make_pair(x - K, y + K);
	}
	else if (vec == 2) {
		return make_pair(x, y);
	}
	else if (vec == 3) {
		return make_pair(x - K, y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T >> K;
	xZonzae.resize(N + 1);
	yZonzae.resize(M + 1);
	dot.resize(T);

	fill(xZonzae.begin(), xZonzae.end(), false);
	fill(yZonzae.begin(), yZonzae.end(), false);

	xPos.push_back(0);
	yPos.push_back(0);
	xZonzae[0] = true;
	yZonzae[0] = true;
	xPos.push_back(N);
	yPos.push_back(M);
	xZonzae[N] = true;
	yZonzae[M] = true;

	for (int i = 0; i < T; i++) {
		cin >> dot[i].first >> dot[i].second;
		int x = dot[i].first;
		int y = dot[i].second;
		if (!xZonzae[x]) {
			xPos.push_back(x);
			xZonzae[x] = true;
		}
		if (!yZonzae[y]) {
			yPos.push_back(y);
			yZonzae[y] = true;
		}
	}

	int ans = 0;

	pair<int, int> ansPos = make_pair(-1, -1);

	for (int i = 0, x_size = xPos.size(); i < x_size; i++) {
		for (int j = 0, y_size = yPos.size(); j < y_size; j++) {
			pair<int, int> temp = Tamsek(xPos[i], yPos[j]);
			if (temp.first != -1 && temp.first > ans) {
				ans = temp.first;
				ansPos = leftUp(xPos[i], yPos[j], temp.second);
			}
		}
	}

	if (ansPos.first == -1) {
		cout << "0 ";
	}
	cout << ansPos.first << ' ' << ansPos.second << '\n';
	cout << ans;
}