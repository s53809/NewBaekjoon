#include<iostream>
using namespace std;
int a = 0;
int d = 0;
int undurbar = 0;
string endscript[50];
void underbar(int c) {
	for (int i = 0; i < 4 * c; i++) {
		cout << "_";
	}
}
void endunderbar(int c) {
	while (c >= 0) {
		for (int i = 0; i < 4 * c; i++) {
			cout << "_";
		}
		cout << "��� �亯�Ͽ���." << endl;
		c -= 1;
	}
}

void Whatisreear(int b) {

	underbar(d);
	cout << "\"����Լ��� ������?\"" << endl;
	if (b > 0) {
		underbar(d);
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
		underbar(d);
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
		underbar(d);
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\" " << endl;

		d += 1;
		Whatisreear(b - 1);
	}
	else {
		underbar(d);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		endunderbar(d);
	}
}


int main() {
	cin >> a;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
	Whatisreear(a);
}