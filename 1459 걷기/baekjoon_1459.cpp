#include <iostream>
#include <algorithm>
typedef long long int lld;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	lld X, Y, W, S;
	cin >> X >> Y >> W >> S;

	if (S <= W) {
		if ((X + Y) % 2 == 0) {
			cout << max(X, Y) * S;
		}
		else {
			cout << (max(X, Y) - 1) * S + W;
		}
		return 0;
	}

	if (S >= W * 2) {
		cout << (X * W) + (Y * W);
	}

	else if (S < W * 2) {
		cout << (min(X, Y) * S) + (abs(X - Y) * W);
	}

}

/*
첫번 째 : 대각선 무빙이 한 블럭 이동 * 2 보다 더 비용이 많이 들면 대각선 무빙은 필요 없다
두번 째 : 대각선 무빙이 한 블럭 이동 *  2 보다 작은 경우 대각선 무빙을 사용할 수 있는 상황이 오면 사용하는 것이 좋다
세번 째 : 대각선 무빙이 한 블럭 이동 보다 비용이 더 작은 경우 : 대각선 무빙으로 갈 수 있는 상황에선 무조건 대각선 무빙을 사용한다
4번째 테스트 케이스 : ( 11 * 18 ) + ( 7 * 7 ) = 198 + 49 = 247
OXO
XOXO
OXO

(2,0), (1,1), (0,2), (2,2), (3,1) : 더했을 때 짝수라면 대각선 무빙으로 무조건 이동 가능
(1,0), (0,1), (2,1), (1,2) : 더했을 때 홀수라면 대각선 무빙으로 이동하고 한번더 비용 청구
몇번 대각선 움직이는가? => 좌푯값중 가장 큰 값
*/