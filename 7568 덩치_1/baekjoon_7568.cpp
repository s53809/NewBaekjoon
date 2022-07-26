#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct triple {
	int first;
	int second;
	int num;
};

int N;
vector<triple> x;

vector<int> ranking;
int maximum = 0;

bool compare(triple a, triple b) {
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	x.resize(N);
	ranking.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
		x[i].num = i;
		ranking[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (x[i].first < x[j].first && x[i].second < x[j].second) {
				ranking[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ranking[i] << ' ';
	}
}

/*
58 180
54 180
58 181
59 179
59 159


*/