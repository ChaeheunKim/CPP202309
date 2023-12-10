
#include <iostream>
#include <string>
#include "user.h"
#include <fstream>
#include <exception>
using namespace std;

const int mapX = 5;
const int mapY = 5; // ������ ����� �迭 ����


// ����� ���� �Լ�
bool checkXY(int user_x1, int user_y1, int user_x2, int user_y2, int mapX, int mapY);
void displayMap(int map[][mapX], User* player1, User* player2);
bool checkGoal(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2);

void checkState(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2, User* player1, User* player2);
User my_user;
bool CheckUser(User* player1, User* player2);
void CurrentUser();
int k = 0;



// ����  �Լ�
int main() {
	int map[mapX][mapY];
	Magician magician;
	Warrior warrior;
	User* player[] = { &magician, &warrior };
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	ifstream is{ "C:/Users/chee0/Downloads/map.txt" };// �� �������� //��� ���� �ʿ�
	if (!is) {
		cerr << "���� ���¿� �����Ͽ����ϴ�" << endl;
		exit(1);
	}
	for (int i = 0; i < mapX; ++i) {
		for (int j = 0; j < mapY; ++j) {
			is >> map[i][j];
		}
	}

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����
		// ������� �Է��� ������ ����
		try {
			string user_input = "";
			CurrentUser();
			cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
			cin >> user_input;   //����ڿ��� �Է¹ޱ�

			if (user_input == "��") {
				// ���� �� ĭ �ö󰡱�
				int user_y = player[k % 2]->GetY() - 1;
				int user_x = player[k % 2]->GetX();
				bool inMap = checkXY(user_x, user_y, user_x, user_y, mapX, mapY);
				if (inMap == false) {
					cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
					user_y += 1;  // ������ �� �ȿ� ���ٸ� ��� ���
					k += 1;
				}
				else {
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
					player[k % 2]->SetY(user_y);
					player[k % 2]->SetX(user_x);
					player[k % 2]->DecreaseHP(1); // �̵����� ü�� �� ĭ ����

					displayMap(map, player[0], player[1]); // ���� �ö� ���� ����
					cout << "ü���� " << player[k % 2]->GetHP() << "�Դϴ�" << endl; //���� ü�� ���
					checkState(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY(), &magician, &warrior); //��, ����, ������ ������ �� �Լ�
				}
			}
			else if (user_input == "��") {
				// �Ʒ��� �� ĭ ��������
				int user_y = player[k % 2]->GetY() + 1;
				int user_x = player[k % 2]->GetX();
				bool inMap = checkXY(user_x, user_y, user_x, user_y, mapX, mapY);
				if (inMap == false) {
					cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
					user_y -= 1; // ������ �� �ȿ� ���ٸ� ��� ���
					k += 1;
				}
				else {
					cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
					player[k % 2]->SetY(user_y);
					player[k % 2]->SetX(user_x);
					player[k % 2]->DecreaseHP(1); // �̵����� ü�� �� ĭ ����

					displayMap(map, player[0], player[1]);// �Ʒ��� �� ĭ ������ ���� ����
					cout << "ü���� " << player[k % 2]->GetHP() << "�Դϴ�" << endl; //���� ü�� ���
					checkState(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY(), &magician, &warrior); //��, ����, ������ ������ �� �Լ�
				}
			}
			else if (user_input == "��") {
				// �������� �̵��ϱ�
				int user_x = player[k % 2]->GetX() - 1;
				int user_y = player[k % 2]->GetY();
				bool inMap = checkXY(user_x, user_y, user_x, user_y, mapX, mapY);
				if (inMap == false) {
					cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
					user_x += 1; // ������ �� �ȿ� ���ٸ� ��� ���
					k += 1;
				}
				else {
					cout << "�������� �̵��մϴ�." << endl;
					player[k % 2]->SetY(user_y);
					player[k % 2]->SetX(user_x);
					player[k % 2]->DecreaseHP(1); // �̵����� ü�� �� ĭ ����
					displayMap(map, player[0], player[1]);// ���ʷ� �� ĭ �� ���� ����
					cout << "ü���� " << player[k % 2]->GetHP() << "�Դϴ�" << endl;; //���� ü�� ���
					checkState(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY(), &magician, &warrior); //��, ����, ������ ������ �� �Լ�
				}
			}
			else if (user_input == "��") {
				// ���������� �̵��ϱ�
				int user_x = player[k % 2]->GetX() + 1;
				int user_y = player[k % 2]->GetY();
				bool inMap = checkXY(user_x, user_y, user_x, user_y, mapX, mapY);
				if (inMap == false) {
					cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
					user_x -= 1; // ������ �� �ȿ� ���ٸ� ��� ���
					k += 1;
				}
				else {
					cout << "���������� �̵��մϴ�." << endl;
					player[k % 2]->SetY(user_y);
					player[k % 2]->SetX(user_x);
					player[k % 2]->DecreaseHP(1); // �̵����� ü�� �� ĭ ����
					displayMap(map, player[0], player[1]); // �����ʷ� �� ĭ �� ���� ����
					cout << "ü���� " << player[k % 2]->GetHP() << "�Դϴ�" << endl;; //���� ü�� ���
					checkState(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY(), &magician, &warrior); //��, ����, ������ ������ �� �Լ�
				}
			}
			else if (user_input == "����") {
				// ���� �����ֱ� �Լ� ȣ��
				displayMap(map, player[0], player[1]);
				k += 1;
			}
			else if (user_input == "����") {
				cout << "�����մϴ�.";
				break;  // ���Ḧ �Է¹����� ����
			}
			else {
				throw invalid_argument("�߸��� �Է��Դϴ�.");
			}   // ����� �Է��� ��/��/��/��/����/���� �ܿ� �ٸ� ���̶�� �߸��� �Է� ���

			// �������� �����ߴ��� üũ
			bool finish = checkGoal(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY());
			if (finish == true) {
				cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
				cout << "������ �����մϴ�." << endl;  //�������� �����ߴٸ� ���ϸ޽��� ��� �� ����
				break;
			}

			//ü���� 0�� �Ǿ��� �� üũ
			bool hp_check = CheckUser(player[0], player[1]);
			if (hp_check == false) {
				cout << "����" << endl;
				cout << "������ �����մϴ�" << endl; //ü���� 0�� �Ǹ� ���� ��� �� ����
				break;
			}
			k += 1;
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	
	
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], User* player1, User* player2) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == player1->GetY() && j == player1->GetX()) {
				cout << "Magician "<<" | ";
			}
			else if (i == player2->GetY() && j == player2->GetX()) {
				cout << "Warrior" << " | ";
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
		cout << " ---------------------------------------" << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x1, int user_y1, int user_x2, int user_y2, int mapX, int mapY) {
	bool checkFlag = false;
	if (user_x1 >= 0 && user_x1 < mapX && user_y1 >= 0 && user_y1 < mapY &&
		user_x2 >= 0 && user_x2 < mapX && user_y2 >= 0 && user_y2 < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2) {
	// ������ �����ϸ� true ��ȯ
	if ((map[user_y1][user_x1] == 4) or (map[user_y2][user_x2] == 4)) {
		return true;
	}
	return false;
}


// ����, ������, �� üũ �Լ�
void checkState(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2, User* player1, User* player2) {
	int posState = map[user_y1][user_x1];
	int posState2 = map[user_y2][user_x2];
	User my_user;
	if ((k % 2) == 0) {
		switch (posState) {
		case 1:
			cout << "�������� �ֽ��ϴ�" << endl;
			break;
		case 2:
			cout << "���� �ֽ��ϴ�. ü���� 2��ŭ ���Դϴ�." << endl;
			player1->DecreaseHP(2); // ü�� 2 ���
			my_user.doAttack();
			player1->doAttack();
			cout << "ü���� " << player1->GetHP() << "�Դϴ�." << endl;
			break;
		case 3:
			cout << " ������ �ֽ��ϴ�. ü���� 2��ŭ ȸ���˴ϴ�." << endl;
			player1->increaseHP(2); //ü�� 2 ȸ��
			cout << "ü���� " << player1->GetHP() << "�Դϴ�." << endl;
			break;
		}  // ���� ��ġ�� ������, ��, ���� �� ������ �̸� ���
	}
	if ((k % 2) == 1) {
		switch (posState2) {
		case 1:
			cout << "�������� �ֽ��ϴ�" << endl;
			break;
		case 2:
			cout << "���� �ֽ��ϴ�. ü���� 2��ŭ ���Դϴ�." << endl;
			player2->DecreaseHP(2); // ü�� 2 ���
			my_user.doAttack();
			player2->doAttack();
			cout << "ü���� " << player2->GetHP() << "�Դϴ�." << endl;
			break;
		case 3:
			cout << " ������ �ֽ��ϴ�. ü���� 2��ŭ ȸ���˴ϴ�." << endl;
			player2->increaseHP(2); //ü�� 2 ȸ��
			cout << "ü���� " << player2->GetHP() << "�Դϴ�." << endl;
			break;
		}  // ���� ��ġ�� ������, ��, ���� �� ������ �̸� ���
	}
}
bool CheckUser(User *player1,User *player2) {
	if (player1->GetHP() <= 0 or player2->GetHP() <= 0) {
		return false;
	}
	else{
		return true;
	}
}
void CurrentUser() {
	if ((k % 2) == 0) {
		cout << "���� ������ Magician �Դϴ�" << endl;
	}
	else if ((k % 2) == 1) {
		cout << "���� ������ Warrior �Դϴ�" << endl;
	}
}
