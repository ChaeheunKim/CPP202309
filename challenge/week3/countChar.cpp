#include <iostream>
using namespace std;

int main() {
	int vowel = 0;
	int consonant = 0;   //����, ���� ���� ���� 0���� �ʱ�ȭ
	cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ����" << endl;

	char ch; //����� �Է� �����ϱ� ���� ����

	while (cin >> ch) {
		switch(ch) {
		case 'a':
			vowel = vowel + 1;  //����ڰ� a �Է��ϸ� ������ ���� 1 �߰�
			break;
		case 'e':
			vowel = vowel + 1; //����ڰ� e �Է��ϸ� ������ ���� 1 �߰�
			break;
		case 'i':
			vowel = vowel + 1; //����ڰ� i �Է��ϸ� ������ ���� 1 �߰�
			break;
		case 'o':
			vowel = vowel + 1; //����ڰ� o �Է��ϸ� ������ ���� 1 �߰�
			break;
		case 'u':
			vowel = vowel + 1; //����ڰ� u �Է��ϸ� ������ ���� 1 �߰�
			break;
		default:
			consonant = consonant + 1; //����ڰ� ���� �Է��ϸ� ������ ���� 1 �߰�

		}
	}
	cout << "���� : " << vowel << endl;
	cout << "���� : " << consonant << endl;  //���
	return 0;
}