#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> str;
int d_x[] = { 0,0,-1,1 };
int d_y[] = { -1,1,0,0 };

int swap(int x1, int y1, int x2, int y2) {
	char box = str[y1][x1];
	str[y1][x1] = str[y2][x2];
	str[y2][x2] = box;
}

int gomsa(int posX, int posY) {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int dir_x;
			int dir_y;
			for (int u = 0; u < 4; u++) {
				dir_x = d_x[u] + j;
				dir_y = d_y[u] + i;
				if (dir_x >= 0 && dir_x < N && dir_y >= 0 && dir_y < N) {
					swap(j, i, dir_x, dir_y);
				}
			}
		}
	}
}