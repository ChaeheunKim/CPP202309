#include <iostream>
#include <string>
using namespace std;

int main() {
	const int STUDENT = 5; // STUDENT�� 5�� ����
	const int SUBJECT = 3; // SUBJECT�� 3���� ����
	int scores[STUDENT][SUBJECT]; // 2���� �迭 ����
	string studentNames[STUDENT]
		= { "����","����","ö��","�̹�","����" };
	string subjectNames[SUBJECT]
		= { "����","����","CPP" }; //�迭�� �л��̸��� �����̸� ����

	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ������ �ϳ��� �Է��ϼ���" << endl;
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];   // �л��� ���� �Է¹޾� ����
		}

	}
	double sum = 0;
	double average = 0;  //sum, average ���� 0���� �ʱ�ȭ
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ��� ������";
		
	    for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];  //sum�� �л��� ���� �����Ͽ� ���ϱ�
		}
		average = sum / SUBJECT; // sum�� ���� ������ ������ ��� ���ϱ�
		cout << average << "�Դϴ�" << endl; //��� ���
		
	}
	return 0;
	

}