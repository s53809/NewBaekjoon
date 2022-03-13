#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
queue<pair<int, int>> x;
vector<int> calculate;
vector<pair<int, int>> qu;
int getsu = 0, shorts = 0;

void cal() {
	while (getsu != N) {
		if (qu.size() != K) {
			for (int i = 0; i < K; i++) {
				if (qu[i].first == 0) {
					qu[i] = x.front();
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	qu.resize(K);
	for (int i = 0; i < N; i++) {
		pair<int, int> dist;
		cin >> dist.second >> dist.first;
		x.push(dist);
	}
	
}