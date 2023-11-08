#include <iostream>
#include <string>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5; // ������ ����� �迭 ����


// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
bool checkhp(int hp);
void checkState(int map[][mapX], int user_x, int user_y);
User my_user;



// ����  �Լ�
int main() {
	my_user.hp = 20;//����� ü�� 20 ����
	
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} }; // ������,����, ������ ��ġ ����

	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ   // ���� ��ġ�� �� ó������ ����

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;   //����ڿ��� �Է¹ޱ�

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;  // ������ �� �ȿ� ���ٸ� ��� ���
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				my_user.DecreaseHP(1); // �̵����� ü�� �� ĭ ����
				displayMap(map, user_x, user_y); // ���� �ö� ���� ����
				cout << "ü���� " << my_user.GetHP() << "�Դϴ�"<<endl; //���� ü�� ���
				checkState(map, user_x, user_y); //��, ����, ������ ������ �� �Լ�
			} 
		}
		else if (user_input == "��") {
			// �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1; // ������ �� �ȿ� ���ٸ� ��� ���
			}
			else {
				cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
				my_user.DecreaseHP(1); // �̵����� ü�� �� ĭ ����
				displayMap(map, user_x, user_y);  // �Ʒ��� �� ĭ ������ ���� ����
				cout << "ü���� " << my_user.GetHP() << "�Դϴ�"<<endl; //���� ü�� ���
				checkState(map, user_x, user_y); //��, ����, ������ ������ �� �Լ�
			}   
		}
		else if (user_input == "��") {
			// �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1; // ������ �� �ȿ� ���ٸ� ��� ���
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				my_user.DecreaseHP(1); // �̵����� ü�� �� ĭ ����
				displayMap(map, user_x, user_y); // ���ʷ� �� ĭ �� ���� ����
				cout << "ü���� " << my_user.GetHP() << "�Դϴ�" << endl;; //���� ü�� ���
				checkState(map, user_x, user_y); //��, ����, ������ ������ �� �Լ�
			}  
		}
		else if (user_input == "��") {
			// ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1; // ������ �� �ȿ� ���ٸ� ��� ���
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				my_user.DecreaseHP(1); // �̵����� ü�� �� ĭ ����
				displayMap(map, user_x, user_y); // �����ʷ� �� ĭ �� ���� ����
				cout << "ü���� " << my_user.GetHP() << "�Դϴ�" << endl;; //���� ü�� ���
				checkState(map, user_x, user_y); //��, ����, ������ ������ �� �Լ�
			}   
		} 
		else if (user_input == "����") {
			// ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;  // ���Ḧ �Է¹����� ����
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}   // ����� �Է��� ��/��/��/��/����/���� �ܿ� �ٸ� ���̶�� �߸��� �Է� ���

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;  //�������� �����ߴٸ� ���ϸ޽��� ��� �� ����
			break;
		}

		//ü���� 0�� �Ǿ��� �� üũ
		bool hp_check = checkhp(my_user.GetHP());
		if (hp_check == true) {
			cout << "����" << endl;
			cout << "������ �����մϴ�" << endl; //ü���� 0�� �Ǹ� ���� ��� �� ����
			break;
		}

	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}                   // �ʹݿ� ������ ��ġ��� ������,��,����, ������ ���
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ� true ��ȯ
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// ü���� �� �ߴ� �� üũ�ϴ� �Լ�
bool checkhp(int hp) {
	if (hp <= 0) {  //ü���� 0������ true ��ȯ
		return true;
	}
	return false;
}

// ����, ������, �� üũ �Լ�
void checkState(int map[][mapX], int user_x, int user_y) {
			int posState = map[user_y][user_x];

				switch (posState) {
				case 1:
					cout << "�������� �ֽ��ϴ�"<<endl;
					break;
				case 2:
					cout << "���� �ֽ��ϴ�. ü���� 2��ŭ ���Դϴ�."<<endl;
					my_user.DecreaseHP(2);  // ü�� 2 ���
					cout << "ü���� " << my_user.hp <<"�Դϴ�."<<  endl;
					break;
				case 3:
					cout << " ������ �ֽ��ϴ�. ü���� 2��ŭ ȸ���˴ϴ�."<<endl;
					my_user.hp = my_user.hp + 2; //ü�� 2 ȸ��
					cout << "ü���� " << my_user.hp << "�Դϴ�."<< endl;
					break;
				}  // ���� ��ġ�� ������, ��, ���� �� ������ �̸� ���
		}