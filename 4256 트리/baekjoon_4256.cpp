#include <iostream>
using namespace std;

int N;
int preorder[1001];
int inorder[1001];
int index[1001];

void PostOrder(int preStart, int preEnd, int inStart, int inEnd) {
	if (preStart >= preEnd || inStart >= inEnd) { return; }

	int rootNode = index[preorder[preStart]];
	int leftNode = rootNode - inStart;
	PostOrder(preStart + 1, preStart + leftNode + 1, inStart, rootNode);
	PostOrder(preStart + leftNode + 1, preEnd, rootNode + 1, inEnd);
	cout << inorder[rootNode] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> preorder[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> inorder[i];
			index[inorder[i]] = i;
		}
		PostOrder(0, N, 0, N);
		cout << '\n';
	}

	
}