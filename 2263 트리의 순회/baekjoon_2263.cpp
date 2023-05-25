#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> inorder;
vector<int> postorder;
vector<int> index;

void makeTree(int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart >= inEnd || postStart >= postEnd) return;
	int rootNode = index[postorder[postEnd - 1]];
	int leftSize = rootNode - inStart;
	cout << inorder[rootNode] << ' ';
	makeTree(inStart, rootNode, postStart, postStart + leftSize);
	makeTree(rootNode + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	inorder.resize(N);
	postorder.resize(N);
	index.resize(N + 1, -1);

	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
		index[inorder[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}
	
	makeTree(0, N, 0, N);
}