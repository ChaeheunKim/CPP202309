#include <iostream>
using namespace std;

int main() {
	int money , price;
	cout << "���� ������ �ִ� �� : ";
	cin >> money;
	cout << "���� ����: ";
	cin >> price;   //���� ������ ���������� �Է¹ޱ�
    
	cout << "�ִ�� �� �� �ִ� ĵ�� = " << money / price << endl; //���� �������� ���� ��(�ִ�� �� �� �ִ� ĵ�� ��) ���
	cout << "ĵ�� ���� �� ���� �� = " << money % price << endl;  //���� �������� ���� ������(���� ��) ���
	return 0;
}