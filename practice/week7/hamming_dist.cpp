#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2; //s1,s2 ���ڿ� ����
	int count = 0; //count ���� 0���� �ʱ�ȭ

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;  // �� �� ���ڿ� �Է¹ޱ�

	if (s1.length() != s2.length())
		cout << "����: ���̰� �ٸ�" << endl; //���̰� �ٸ��ٸ� ���� ���
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
			    count += 1;
		}
		cout << "�ع� �Ÿ��� " << count << endl;
	}   // ���ڰ� �ٸ� ���� ���� ���
	
	return 0;
}