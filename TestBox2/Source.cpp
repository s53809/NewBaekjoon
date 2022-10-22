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
		cout << "라고 답변하였지." << endl;
		c -= 1;
	}
}

void Whatisreear(int b) {

	underbar(d);
	cout << "\"재귀함수가 뭔가요?\"" << endl;
	if (b > 0) {
		underbar(d);
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
		underbar(d);
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
		underbar(d);
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\" " << endl;

		d += 1;
		Whatisreear(b - 1);
	}
	else {
		underbar(d);
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
		endunderbar(d);
	}
}


int main() {
	cin >> a;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
	Whatisreear(a);
}