#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	int ans;  //i 와 ans 정수 선언
	cout << "산수 문제를 자동으로 출제합니다" << endl;

	while (true) {
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;  // 수 랜덤으로 저장

		cout << firstNum << "+" << secondNum << "="; // 랜덤 인 수로 덧셈 문제 출제
		cin >> ans;
		if (firstNum + secondNum == ans) {
			cout << "맞았습니다" << endl;
			break;  // 정답이 맞으면 맞았다가 출력하고 프로그램 종료
         }
		else {
			cout << "틀렸습니다." << endl;
		}  // 틀렸으면 틀렸다고 출력하고 다시 출제

	}
	return 0;
}