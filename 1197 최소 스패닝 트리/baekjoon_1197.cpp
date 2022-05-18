#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
	int node[2];
	int distance;
	Edge() {
		this->node[0] = 0;
		this->node[1] = 0;
		this->distance = 0;
	}
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int V, E;
vector<Edge> x;
vector<int> root;
int ans = 0;

int getParent(int N) {
	if (root[N] == N) return N;
	return root[N] = getParent(root[N]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) root[b] = a;
	else root[a] = b;
}

bool find(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	x.resize(E);
	root.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x[i] = Edge(a, b, c);
	}

	sort(x.begin(), x.end());

	for (int i = 1; i < V + 1; i++) {
		root[i] = i;
	}

	for (int i = 0; i < E; i++) {
		if (!find(x[i].node[0], x[i].node[1])) { // 사이클이 아니라면
			ans += x[i].distance;
			unionParent(x[i].node[0], x[i].node[1]);
		}
	}

	cout << ans;
}