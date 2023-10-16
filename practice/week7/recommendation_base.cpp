#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main () {
	const int NUM_USERS = 3;
    const int NUM_ITEMS = 3; //����ڿ� �׸� ���� 3���� ����
	int userPreferences[NUM_USERS][NUM_ITEMS];
	
	// ����ڿ� �׸� ���� ��ȣ���� �Է� �޾� 2���� �迭 �ʱ�ȭ
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "�����" << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����) ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j]; // ��ȣ�� �Է� �ޱ�
		}
	}

	//�� ����ڿ� ���� ��õ �׸� ã��
	for (int i = 0; i < NUM_USERS; ++i) {
	     int maxPreferenceindex = 0; // ��õ �׸� �ʱ�ȭ
		 for (int j = 1; j < NUM_ITEMS; ++j) {
			 if (userPreferences[i][j] > userPreferences[i][maxPreferenceindex]) {
				 maxPreferenceindex = j; //��ȣ���� ���� ū ���� ��õ�׸����� ����
			 }
		 }
	     // ����ڿ��� ��õ�ϴ� �׸� ���
		 cout << "�����" << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		 cout << (maxPreferenceindex + 1) << std::endl;
    }

	return 0;
}