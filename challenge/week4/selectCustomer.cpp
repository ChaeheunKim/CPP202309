#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3; //maxPeople 3������ ����
	string names[maxPeople]; // names �迭 ���ڿ��� ����
	int ages[maxPeople];  //ages �迭 ������ ����

	for (int i = 0; i < maxPeople; ++i) { // ��� �� ��ŭ �ݺ�
		cout << "���" << i + 1 << "�� �̸�: ";
		cin >> names[i];
		cout << "���" << i + 1 << "�� ����: ";
		cin >> ages[i];           // �̸��� ���� �Է� �ް� �迭�� ����
	}

	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;       // Ư�� ���� �Է¹ޱ�

	cout << ageThreshold << "�� �̻��� ����:\n";
	int detectedPeople = 0;
	for (int i = 0; i < maxPeople; i++) {
		if (ages[i] >= ageThreshold) {    
			cout << names[i] << " (" << ages[i] << "��)\n";
			detectedPeople++;          // Ư�� ���� �̻��� �� ��� �� detectedPeople�� 1 ���ϱ�
		}
	}
	if (detectedPeople == 0) {
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
	}   // Ư�� ���� �̻��� ���� ���ٸ� ���ٰ� ���

	return 0;



}