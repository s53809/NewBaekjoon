#include <iostream>
using namespace std;

class BinaryTree {
public:
	BinaryTree* leftNode;
	BinaryTree* rightNode;
	BinaryTree* rootNode;
	int num;

	BinaryTree(int num) {
		leftNode = nullptr;
		rightNode = nullptr;
		rootNode = nullptr;
		this->num = num;
	}

	BinaryTree() {
		leftNode = nullptr;
		rightNode = nullptr;
		rootNode = nullptr;
		this->num = 0;
	}
};

BinaryTree root;
BinaryTree* curNode;

void InputBinaryTree(int Num) {
	if (curNode->num > Num) {
		BinaryTree left(Num);
		curNode->leftNode = &left;
		left.rootNode = curNode;
		curNode = curNode->leftNode;
	}
	else if (curNode->num < Num) {
		if (curNode == &root) {
			BinaryTree right(Num);
			curNode->rightNode = &right;
			right.rootNode = curNode;
			curNode = curNode->rightNode;
		}
		else if (curNode->rootNode->num < Num) {
			curNode = curNode->rootNode;
			InputBinaryTree(Num);
		}
		else {
			BinaryTree right(Num);
			curNode->rightNode = &right;
			right.rootNode = curNode;
			curNode = curNode->rightNode;
		}
	}
}

void PrintHuwi(BinaryTree* cur) {
	if (cur->leftNode != nullptr) {
		PrintHuwi(cur->leftNode);
	}
	if (cur->rightNode != nullptr) {
		PrintHuwi(cur->rightNode);
	}
	cout << cur->num;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int inputNum;
	cin >> inputNum;
	root.num = inputNum;
	curNode = &root;
	while (true) {
		cin >> inputNum;
		if (inputNum == -1) break;
		InputBinaryTree(inputNum);
	}

	PrintHuwi(&root);
}