#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long mi, ma;
vector<pair<int, bool>> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> mi >> ma;

	x.resize(ma - mi + 1);

	int x_length = x.size();
	
	for (int i = 0; i < x_length; i++) {
		x[i].first = mi + i;
		x[i].second = false;
	}

	for (long long i = 2; i * i <= ma; i++) {
		
	}
}