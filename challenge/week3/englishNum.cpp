#include <iostream>
using namespace std;

int main() {
	int number;    //number ���� ������ ����
	cout << "���ڸ� �Է��Ͻÿ� : ";      
	cin >> number;  //���� �Է� �ޱ�
	if (number == 0)
		cout << "zero\n"; //�Է¹��� ������ 0�̸� ���� �ٿ� zero ���
	else if (number == 1) 
		cout << "one\n";   //�Է¹��� ������ 1�̸� ���� �ٿ� one ���
	else
		cout << "many\n";  // �Է¹��� ������ 0�� 1�� �ƴϸ� ���� �ٿ� many ���

		return 0;
		

}