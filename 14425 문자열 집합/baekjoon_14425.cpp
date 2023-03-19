#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	set<string> x;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		x.insert(str);
	}

	int cnt = 0;
	
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (x.find(str) != x.end()) {
			cnt++;
		}
	}

	cout << cnt << '\n';
}