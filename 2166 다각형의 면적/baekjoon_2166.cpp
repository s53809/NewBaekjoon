#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<double, double> ll;

double NullBe(double x1, double y1, double x2, double y2, double x3, double y3) {
	return (((x1 * y2) + (x2 * y3) + (x3 * y1) - (x2 * y1) - (x3 * y2) - (x1 * y3)) / 2);
}

int main() {
	int N;
	cin >> N;
	vector<ll> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i].first >> x[i].second;
	}

	double ans = 0;
	for (int i = 1; i < N - 1; i++) {
		ans += NullBe(x[0].first, x[0].second, x[i].first, x[i].second, x[i + 1].first, x[i + 1].second);
	}
	printf("%.1lf", abs(ans));
}