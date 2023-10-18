#include <iostream>
#include <string>
using namespace std;


string toLowerStr(string str) {
	string s1 = str;
	for (char& c : s1) {
		c = tolower(c);
	}
	return s1;  // ���ڿ� �ҹ��ڷ� ��ȯ
}

string toUpperStr(string str) {
	string s1 = str;
	for (char& c : s1) {
		c = toupper(c);
	}
	return s1;  //���ڿ� �빮�ڷ� ��ȯ
}

int calcHammingDist(string s1, string s2) {
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);  // ���ڿ��� ��� �ҹ��ڷ� ��ȯ
	int count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;
	}     // ��ġ ���� �ʴ� �κ��� ������ count�� ����
	return 0;
}

int main() {
	string s1, s2; //s1,s2 ���ڿ� ����

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;  // �� �� ���ڿ� �Է¹ޱ�

	if (s1.length() != s2.length()) {
		cout << "����: ���̰� �ٸ�" << endl;
	}//���̰� �ٸ��ٸ� ���� ���
	else {
		int count = calcHammingDist(s1, s2); // ��,�ҹ��� ����
		cout << "�ع� �Ÿ��� " << count << endl;
	}   // ���ڰ� �ٸ� ���� ���� ���

	return 0;
}