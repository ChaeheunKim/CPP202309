#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
const int NUM_USERS = 3;
const int NUM_ITEMS = 3; //����ڿ� �׸� ���� 3���� ����
int userpreferences[NUM_USERS][NUM_ITEMS];


void initializePreferences(int userpreferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "�����" << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����) ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userpreferences[i][j]; // ��ȣ�� �Է� �ޱ�
		}
	}
}

void findRecommendedItems(const int userpreferences[NUM_USERS][NUM_ITEMS]) {
	//�� ����ڿ� ���� ��õ �׸� ã��
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceindex = 0; // ��õ �׸� �ʱ�ȭ
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userpreferences[i][j] > userpreferences[i][maxPreferenceindex]) {
				maxPreferenceindex = j; //��ȣ���� ���� ū ���� ��õ�׸����� ����]
			}
		}
		// ����ڿ��� ��õ�ϴ� �׸� ���
		cout << "�����" << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceindex + 1) << std::endl;
	}
}

int main() {
	initializePreferences(userpreferences);
	findRecommendedItems(userpreferences);
	return 0;  // �Լ� �����ͼ� ���
}