#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<string> str;

void zaegwi(int stac) {
	if (stac == N) {
		for (int i = 0; i < stac * 4; i++) cout << '_';
		cout << str[0];
		for (int i = 0; i < stac * 4; i++) cout << '_';
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = 0; i < stac * 4; i++) cout << '_';
		cout << "��� �亯�Ͽ���.\n";
		return;
	}
	int j = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < stac * 4; i++) cout << '_';
		cout << str[j];
	}
	zaegwi(++stac);
	stac--;
	for (int i = 0; i < stac * 4; i++) cout << '_';
	cout << "��� �亯�Ͽ���.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	str.push_back("\"����Լ��� ������?\"\n");
	str.push_back("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
	str.push_back("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
	str.push_back("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
	zaegwi(0);
}