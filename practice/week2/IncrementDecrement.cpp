#include <iostream>
using namespace std;

int main() {
	int x = 1; //x�� 1�� �ʱ�ȭ
	cout << "x = " << x++ << endl; //x ��� �� x�� 1 ���ϱ�
	cout << "x = " << x++ << endl; //x ��� �� x�� 1 ���ϱ�
	cout << "x = " << ++x << endl; //x�� 1 ���� �� ����ϱ�
	cout << "x = " << x-- << endl;  //x ��� �� x�� 1 ����
	cout << "x = " << x-- << endl;  //x ��� �� x�� 1 ����
	cout << "x = " << --x << endl;  //x�� 1 �A �� ����ϱ�

	return 0;

}
