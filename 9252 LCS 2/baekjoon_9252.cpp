#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string A, B;
vector<vector<int>> x;

//LCS = max(x[i - 1][j], x[i][j - 1]);

int LCS(int i, int j) {
	if (i == 0 || j == 0) return 0;
	if (x[i][j] != -1) return x[i][j];

	if (A[i - 1] == B[j - 1]) return x[i][j] = min(LCS(i - 1, j - 1), min(LCS(i - 1, j), LCS(i, j - 1))) + 1;
	else return x[i][j] = max(LCS(i - 1, j - 1), max(LCS(i - 1, j), LCS(i, j - 1)));
}

void PrintLCS(int i, int j) {
	if (i == 0 || j == 0) return;
	if (A[i - 1] == B[j - 1]) {
		PrintLCS(i - 1, j - 1);
		cout << A[i - 1];
	}
	else {
		if (x[i - 1][j] >= x[i][j - 1]) PrintLCS(i - 1, j);
		else PrintLCS(i, j - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> A >> B;
	x.resize(A.size() + 1, vector<int>(B.size() + 1, -1));
	cout << LCS(A.size(), B.size()) << '\n';
	PrintLCS(A.size(), B.size());
}