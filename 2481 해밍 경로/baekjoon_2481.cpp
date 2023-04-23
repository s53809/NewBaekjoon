#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int N, K, M;
vector<string> x;
map<int, bool> dic;

int binaryTrans(string str) {
	int ans = 0;
	for (int i = 0, str_size = str.size(); i < str_size; i++) {
		ans += (str[i] - '0') * pow(2, str_size - i - 1);
	}
	return ans;
}

void BFS(int endPos) {

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> K;
	x.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
		dic.insert({ binaryTrans(x[i]),false });
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int endPos;
		cin >> endPos;
	}
}