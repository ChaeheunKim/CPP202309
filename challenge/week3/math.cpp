#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	int ans;  //i �� ans ���� ����
	int a; //���� ���� a ���� ����
	a = 0;
	cout << "��� ������ �ڵ����� �����մϴ�" << endl;

	while (true) {
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;  // �� �������� ����

		cout << firstNum << "+" << secondNum << "="; // ���� �� ���� ���� ���� ����
		cin >> ans;
		if (firstNum + secondNum == ans) {
			cout << "�¾ҽ��ϴ�" << endl;
			a = a + 1;
				if (a > 4)
					break;// ������ ������ �¾Ҵٰ� ����ϰ� ���α׷� ����
         }
		else {
			cout << "Ʋ�Ƚ��ϴ�." << endl;
		}

	}
}