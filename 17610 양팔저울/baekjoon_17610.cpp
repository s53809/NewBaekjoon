#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S = 0;
vector<int> x;
vector<vector<int>> temp;
vector<int> copy_x;
vector<int> xtemp;
vector<bool> isDone;
int maxNumber = 0;

void output(int n) {
	xtemp[n] = 1;
	int length = xtemp.size();
	do {
		vector<int> box;
		for (int i = 0; i < length; i++) {
			if (xtemp[i] == 1) {
				box.push_back(x[i]);
			}
		}
		temp.push_back(box);
	} while (prev_permutation(xtemp.begin(), xtemp.end()));
}

void run(int n) {
	int nLength = temp[n].size();
	int NoHap = 0;
	vector<bool> isGyop(maxNumber + 1, false);
	for (int i = 0; i < nLength; i++) {
		NoHap += temp[n][i];
		isGyop[temp[n][i]] = true;
	}
	int tempLength = temp.size();
	for (int i = 0; i < tempLength; i++) {
		nLength = temp[i].size();
		int hap = 0;
		for (int j = 0; j < nLength; j++) {
			if (isGyop[temp[i][j]]) {
				hap = 0;
				break;
			}
			hap += temp[i][j];
		}
		hap -= NoHap;
		if (hap <= 0) {
			continue;
		}
		isDone[hap] = true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	x.resize(N);
	xtemp.resize(N);
	fill(xtemp.begin(), xtemp.end(), 0);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		S += x[i];
	}
	sort(x.begin(), x.end());
	maxNumber = x[N - 1];
	isDone.resize(S + 1);
	fill(isDone.begin(), isDone.end(), false);
	for (int i = 0; i < N; i++) {
		output(i);
	}
	int temp_length = temp.size();
	for (int i = 0; i < temp_length; i++) {
		int hap = 0;
		int tempI_length = temp[i].size();
		for (int j = 0; j < tempI_length; j++) {
			hap += temp[i][j];
		}
		isDone[hap] = true;
	}
	for (int i = 0; i < temp_length; i++) {
		run(i);
	}
	int falseGetsu = 0;
	for (int i = 1; i <= S; i++) {
		if (!isDone[i]) {
			falseGetsu++;
		}
	}
	cout << falseGetsu;
}