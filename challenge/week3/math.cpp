#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	int ans;  //i �� ans ���� ����
	cout << "��� ������ �ڵ����� �����մϴ�" << endl;

	while (true) {
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;  // �� �������� ����

		cout << firstNum << "+" << secondNum << "="; // ���� �� ���� ���� ���� ����
		cin >> ans;
		if (firstNum + secondNum == ans) {
			cout << "�¾ҽ��ϴ�" << endl;
			break;  // ������ ������ �¾Ҵٰ� ����ϰ� ���α׷� ����
         }
		else {
			cout << "Ʋ�Ƚ��ϴ�." << endl;
		}  // Ʋ������ Ʋ�ȴٰ� ����ϰ� �ٽ� ����

	}
	return 0;
}