#include <iostream>
using namespace std;

int main() {
	int a, b, c, smallest;   //a,b,c, ���� ���� ������ ������ ����
	cout << "3 ���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c;    //a,b,c ������ �Է� �ޱ�

	if (a < b && a < c)
		smallest = a;         //a�� b,c���� ������ smallest ������ a ����
	else if (b < a && b < c)
		smallest = b;         //b�� a,c ���� ������ smallest ������ b ����
	else
		smallest = c;    //���� �� ������ ��� �����̸� smallest ������ c ����
	cout << "���� ���� ������ " << smallest << endl;  // ���� ���� ���� smallest ���
	return 0;
}