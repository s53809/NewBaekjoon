#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int i = 0;
int ans = 0;

void insert(int posY, int posX, int num) {
	if (posY == r && posX == c) {
		cout << ans << '\n';
		return;
	}
	if (posY <= r && r < posY + num && posX <= c && c < posX + num) {
		insert(posY, posX, num / 2);
		insert(posY, posX + num / 2, num / 2);
		insert(posY + num / 2, posX, num / 2);
		insert(posY + num / 2, posX + num / 2, num / 2);
	}
	else {
		ans += num * num;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> r >> c;

	insert(0, 0, (1 << N));
}