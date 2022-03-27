#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
queue<pair<int, int>> x;
vector<int> calculate;
vector<pair<int, int>> qu;
long long getsu = 0, shorts = 2e9;
long long answer = 0;
vector<bool> isEmpty;

void cal() {
	while (getsu < N) {
		shorts = 2e9;
		int boollength = isEmpty.size();
		for (int i = 0; i < K; i++) {
			if (isEmpty[i] && !x.empty()) {
				qu[i] = x.front();
				isEmpty[i] = false;
				x.pop();
			}
			if (!isEmpty[i]) {
				if (shorts > qu[i].first) {
					shorts = qu[i].first;
				}
			}
		}
		for (int i = K - 1; i >= 0; i--) {
			if (shorts == qu[i].first && !isEmpty[i]) {
				getsu++;
				answer += getsu * qu[i].second;
				isEmpty[i] = true;
			}
			else {
				qu[i].first -= shorts;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> K;
	qu.resize(K);
	isEmpty.resize(K);
	fill(isEmpty.begin(), isEmpty.end(), true);
	for (int i = 0; i < N; i++) {
		pair<int, int> dist;
		cin >> dist.second >> dist.first;
		x.push(dist);
	}
	cal();
	cout << answer;
}