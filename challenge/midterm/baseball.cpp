#include <iostream>
#include <string>
using namespace std;
bool numCheck(int number, int& firstNum, int& secondNum, int& thirdNum);


int main() {

	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	int firstNum; // ������ ù��° �ڸ���
	int secondNum; // ������ �ι�° �ڸ���
	int thirdNum; // ������ ����° �ڸ���

	while (1) {

		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		same = numCheck(randomNum, firstNum, secondNum, thirdNum);
		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		int guessFirst; // ������ ������ ù��° �ڸ���
		int guessSecond; // ������ ������ �ι�° �ڸ���
		int guessThird; // ������ ������ ����° �ڸ���


		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
			if (to_string(userNumber).length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}

			same = numCheck(userNumber, guessFirst, guessSecond, guessThird);
			if (same == false) {
				cout << "�ߺ��� ���ڰ� �ֽ��ϴ�" << endl;
				continue; // �ߺ� ���
			}
			if (same == true) {
				break;
			}



		}

		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ����ۼ�
		string randomNumStr = to_string(randomNum);
		string userstr = to_string(userNumber);//�Է¹��� ���� ���� �� ���ڿ��� �ٲٱ�
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (randomNumStr[i] == userstr[j]) { //�Է¹��� ���� ���� ���� ���� ���ڰ� �ִٸ�
					if (i == j) {   //���� ��ġ�� �� 
						strike++;
					}
					else {     // �ٸ� ��ġ�� ��
						ball++;
					}
				}
			}
		}
		//��Ʈ ���
		cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;
		// ���� �� ����ϰ� ����
		if (strike == 3) {

			cout << "������ ������ϴ�. �����մϴ�.";
			break;
		}

		turn += 1;
	}


	return 0;
}
//numcheck �Լ�
bool numCheck(int number, int& firstNum, int& secondNum, int& thirdNum) {
	firstNum = number / 100;
	secondNum = (number / 10) % 10;
	thirdNum = number % 10; //�ڸ� �� ����
	bool same = false;
	if (firstNum != secondNum && thirdNum != secondNum && firstNum != thirdNum) {
		same = true;
	}  // ��� ���� �ٸ� �� üũ

	return same;
}
//����: 567

