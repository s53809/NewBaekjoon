#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> x;
int N;

typedef struct Node {
	int first;
	int second;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<Node> qu;

	Node x;
	x.first = 1;
	x.second = 2;

	qu.push(x)
}