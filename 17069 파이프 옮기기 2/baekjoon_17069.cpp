#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Pipe {
	long long garo;
	long long sero;
	long long daegak;
};

int N;
int x[34][34];
Pipe sum[34][34];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x[i][j];
		}
	}

	for (int i = 0; i < 34; i++) {
		for (int j = 0; j < 34; j++) {
			sum[i][j].garo = 0;
			sum[i][j].sero = 0;
			sum[i][j].daegak = 0;
		}
	}

	sum[1][1].garo = 1;
	sum[1][2].garo = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 3; j <= N; j++) {
			if (x[i][j] != 1) {
				sum[i][j].garo = sum[i][j - 1].garo + sum[i][j - 1].daegak;
				sum[i][j].sero = sum[i - 1][j].daegak + sum[i - 1][j].sero;
				if (x[i - 1][j] != 1 && x[i][j - 1] != 1) {
					sum[i][j].daegak = sum[i - 1][j - 1].garo + sum[i - 1][j - 1].daegak + sum[i - 1][j - 1].sero;
				}
			}
		}
	}

// 	for (int i = 1; i <= N; i++) {
// 		for (int j = 1; j <= N; j++) {
// 			cout << "(" << sum[i][j].garo << ", " << sum[i][j].daegak << ", " << sum[i][j].sero << ") ";
// 		}
// 		cout << '\n';
// 	}

	cout << sum[N][N].garo + sum[N][N].sero + sum[N][N].daegak;
	
}