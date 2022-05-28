#include <iostream>
#include <vector>
using namespace std;

int N;
int brokenNum;
vector<int> x;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> brokenNum;
	x.resize(brokenNum);
	for (int i = 0; i < brokenNum; i++) {
		cin >> x[i];
	}

}