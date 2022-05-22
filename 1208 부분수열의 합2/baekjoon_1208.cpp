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

	leftExplore(num + 1, sum + arr[num]); // ���� ���� ���ϰ� �Ѿ ��
	leftExplore(num + 1, sum); // �ȴ��ϰ� �Ѿ ��
} 

void rightExplore(int num, int sum) {
	if (num == N) {
		cnt += x[S - sum]; // ���� �κ��հ� ������ ���� ��츦 �����ش�
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

	if (S == 0) cout << cnt - 1;// �ƿ� �� ���� ��� ����
	else cout << cnt;
	return 0;
}