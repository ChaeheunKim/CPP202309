#include <iostream>
using namespace std;

int main() {
	int userInput; //userInput ������ ����
	
	for (int i = 0; i < 10; ++i) {
		cout << "������ 10�� �Է��ϼ���(0�� �Է��ϸ� ����) : " << endl;
		cin >> userInput;  //����ڷκ��� ���� �Է� �ޱ�
		cout << "�Է� �� : " << userInput << "Ƚ�� : " << i << endl;	 //�Է� ���� Ƚ�� ���
		if (userInput == 0) 
			break;  // 0 �Է��ϸ� ����
	}
	return 0;
}