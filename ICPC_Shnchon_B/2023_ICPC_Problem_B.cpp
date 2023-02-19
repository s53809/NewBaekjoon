#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> arr;

int d_x[] = { -1,0,1,-1,1,-1,0,1 };
int d_y[] = { -1,-1,-1,0,0,1,1,1 };

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

pair<int, int> find(string str) {
	int dir_x[] = { 1,4,7 };
	int dir_y[] = { 1,4,7 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			if (arr[dir_y[i]][dir_x[j]] == str) {
				return make_pair(dir_x[j], dir_y[i]);
			}
		}
	}
	return make_pair(-1, -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	arr.resize(9);
	for (int i = 0; i < 9; i++) {
		arr[i].resize(9);
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	vector<string> parents;
	for (int i = 0; i < 8; i++) {
		int dir_x = 4 + d_x[i];
		int dir_y = 4 + d_y[i];
		parents.push_back(arr[dir_y][dir_x]);
	}
	sort(parents.begin(), parents.end());

	for (int i = 0; i < 8; i++) {
		pair<int,int> pos = find(parents[i]);
		if (pos.first == -1 && pos.second == -1) {
			for (int t = 0; t < 100; t++) {
				cout << "출력초과 뜨게 하기!!\n";
			}
		}

		cout << "#" << i + 1 << ". " << parents[i] << '\n';

		vector<string> childs;
		for (int j = 0; j < 8; j++) {
			int dir_x = pos.first + d_x[j];
			int dir_y = pos.second + d_y[j];
			childs.push_back(arr[dir_y][dir_x]);
		}
		sort(childs.begin(), childs.end());

		for (int j = 0; j < 8; j++) {
			cout << "#" << i + 1 << "-" << j + 1 << ". " << childs[j] << '\n';
		}
	}
}