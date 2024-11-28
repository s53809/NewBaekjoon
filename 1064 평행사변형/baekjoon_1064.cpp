#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
typedef pair<double, double> dd;

dd a, b, c;

dd FindDir(dd A, dd B) {
	return { B.first - A.first, B.second - A.second };
}

dd plusVec(dd A, dd B) {
	return { A.first + B.first, A.second + B.second };
}

double findDist(dd A, dd B) {
	return sqrt(((B.first - A.first) * (B.first - A.first)) + ((B.second - A.second) * (B.second - A.second)));
}

double findDullae(dd A, dd B, dd C) {
	return (2 * findDist(A, B)) + (2 * findDist(A, C));
}

void print_with_precision(double num) {
	if (num == (int)num) {
		printf("%.1f", num);
	}
	else {
		printf("%.15g", num);
	}
}

int main() {
	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
	if ((b.second - a.second) * (c.first - a.first) == (c.second - a.second) * (b.first - a.first)) { cout << "-1.0"; return 0; }
	vector<double> point;
	point.push_back(findDullae(a, b, c));
	point.push_back(findDullae(a, b, plusVec(FindDir(b, a), c)));
	point.push_back(findDullae(b, c, a));
	point.push_back(findDullae(b, c, plusVec(FindDir(c, b), a)));
	point.push_back(findDullae(a, c, b));
	point.push_back(findDullae(a, c, plusVec(FindDir(c, a), b)));

	/*for (int i = 0; i < 6; i++) {
		cout << point[i] << '\n';
	}*/
	sort(point.begin(), point.end());

	print_with_precision(point[5] - point[0]);
	
}