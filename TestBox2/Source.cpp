#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> x;
	x.push_back(0);
	x.push_back(5);
	x.push_back(6);
	x.push_back(3);
	x.push_back(9);
	x.push_back(2);
	x.push_back(2);

	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << ' ';
	}
	cout << '\n';

	compress(x);

	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << ' ';
	}
}