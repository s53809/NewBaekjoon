#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, S;
map<int, int> x;
vector<int> arr;
long long cnt = 0;

void leftExplore(int num, int sum) {
	if (num == N / 2) {
		x[sum]++;
		return;
	}

	leftExplore(num + 1, sum + arr[num]); // 현재 값을 더하고 넘어갈 때
	leftExplore(num + 1, sum); // 안더하고 넘어갈 떄
} 

void rightExplore(int num, int sum) {
	if (num == N) {
		cnt += x[S - sum]; // 왼쪽 부분합과 더했을 때의 경우를 더해준다
		return;
	}

	rightExplore(num + 1, sum + arr[num]);
	rightExplore(num + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	leftExplore(0, 0);
	rightExplore(N / 2, 0);

	if (S == 0) cout << cnt - 1;// 아예 안 더한 경우 빼줌
	else cout << cnt;
	return 0;
}