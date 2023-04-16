#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	if (N * 100 >= M) cout << "Yes";
	else cout << "No";
}