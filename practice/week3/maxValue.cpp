#include <iostream>
using namespace std;

int main() {
	int a, b, c, largest;   //a,b,c, ���� ū ������ ������ ����
	cout << "3 ���� ������ �Է��Ͻÿ� : "; 
	cin >> a >> b >> c;    //a,b,c ������ �Է� �ޱ�

	if (a > b && a > c)
		largest = a;         //a�� b,c���� ũ�� largest ������ a ����
	else if (b > a && b > c)
		largest = b;         //b�� a,c ���� ũ�� largest ������ b ����
	else
		largest = c;    //���� �� ������ ��� �����̸� largest ������ c ����
	cout << "���� ū ������ " << largest << endl;  // ���� ū ���� largest ���
	return 0;
}