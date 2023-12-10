
#include <iostream>
#include <string>
#include "user.h"
#include <fstream>
#include <exception>
using namespace std;

const int mapX = 5;
const int mapY = 5; // 게임이 진행될 배열 설정


// 사용자 정의 함수
bool checkXY(int user_x1, int user_y1, int user_x2, int user_y2, int mapX, int mapY);
void displayMap(int map[][mapX], User* player1, User* player2);
bool checkGoal(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2);

void checkState(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2, User* player1, User* player2);
User my_user;
bool CheckUser(User* player1, User* player2);
void CurrentUser();
int k = 0;



// 메인  함수
int main() {
	int map[mapX][mapY];
	Magician magician;
	Warrior warrior;
	User* player[] = { &magician, &warrior };
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	ifstream is{ "C:/Users/chee0/Downloads/map.txt" };// 맵 가져오기 //경로 수정 필요
	if (!is) {
		cerr << "파일 오픈에 실패하였습니다" << endl;
		exit(1);
	}
	for (int i = 0; i < mapX; ++i) {
		for (int j = 0; j < mapY; ++j) {
			is >> map[i][j];
		}
	}

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		// 사용자의 입력을 저장할 변수
		try {
			string user_input = "";
			CurrentUser();
			cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
			cin >> user_input;   //사용자에게 입력받기

			if (user_input == "상") {
				// 위로 한 칸 올라가기
				int user_y = player[k % 2]->GetY() - 1;
				int user_x = player[k % 2]->GetX();
				bool inMap = checkXY(user_x, user_y, user_x, user_y, mapX, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					user_y += 1;  // 유저가 맵 안에 없다면 경고 출력
					k += 1;
				}
				else {
					cout << "위로 한 칸 올라갑니다." << endl;
					player[k % 2]->SetY(user_y);
					player[k % 2]->SetX(user_x);
					player[k % 2]->DecreaseHP(1); // 이동으로 체력 한 칸 감소

					displayMap(map, player[0], player[1]); // 위로 올라간 상태 저장
					cout << "체력은 " << player[k % 2]->GetHP() << "입니다" << endl; //남은 체력 출력
					checkState(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY(), &magician, &warrior); //적, 포션, 아이템 만났을 때 함수
				}
			}
			else if (user_input == "하") {
				// 아래로 한 칸 내려가기
				int user_y = player[k % 2]->GetY() + 1;
				int user_x = player[k % 2]->GetX();
				bool inMap = checkXY(user_x, user_y, user_x, user_y, mapX, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					user_y -= 1; // 유저가 맵 안에 없다면 경고 출력
					k += 1;
				}
				else {
					cout << "아래로 한 칸 내려갑니다." << endl;
					player[k % 2]->SetY(user_y);
					player[k % 2]->SetX(user_x);
					player[k % 2]->DecreaseHP(1); // 이동으로 체력 한 칸 감소

					displayMap(map, player[0], player[1]);// 아래로 한 칸 내려간 상태 저장
					cout << "체력은 " << player[k % 2]->GetHP() << "입니다" << endl; //남은 체력 출력
					checkState(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY(), &magician, &warrior); //적, 포션, 아이템 만났을 때 함수
				}
			}
			else if (user_input == "좌") {
				// 왼쪽으로 이동하기
				int user_x = player[k % 2]->GetX() - 1;
				int user_y = player[k % 2]->GetY();
				bool inMap = checkXY(user_x, user_y, user_x, user_y, mapX, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					user_x += 1; // 유저가 맵 안에 없다면 경고 출력
					k += 1;
				}
				else {
					cout << "왼쪽으로 이동합니다." << endl;
					player[k % 2]->SetY(user_y);
					player[k % 2]->SetX(user_x);
					player[k % 2]->DecreaseHP(1); // 이동으로 체력 한 칸 감소
					displayMap(map, player[0], player[1]);// 왼쪽로 한 칸 간 상태 저장
					cout << "체력은 " << player[k % 2]->GetHP() << "입니다" << endl;; //남은 체력 출력
					checkState(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY(), &magician, &warrior); //적, 포션, 아이템 만났을 때 함수
				}
			}
			else if (user_input == "우") {
				// 오른쪽으로 이동하기
				int user_x = player[k % 2]->GetX() + 1;
				int user_y = player[k % 2]->GetY();
				bool inMap = checkXY(user_x, user_y, user_x, user_y, mapX, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					user_x -= 1; // 유저가 맵 안에 없다면 경고 출력
					k += 1;
				}
				else {
					cout << "오른쪽으로 이동합니다." << endl;
					player[k % 2]->SetY(user_y);
					player[k % 2]->SetX(user_x);
					player[k % 2]->DecreaseHP(1); // 이동으로 체력 한 칸 감소
					displayMap(map, player[0], player[1]); // 오른쪽로 한 칸 간 상태 저장
					cout << "체력은 " << player[k % 2]->GetHP() << "입니다" << endl;; //남은 체력 출력
					checkState(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY(), &magician, &warrior); //적, 포션, 아이템 만났을 때 함수
				}
			}
			else if (user_input == "지도") {
				// 지도 보여주기 함수 호출
				displayMap(map, player[0], player[1]);
				k += 1;
			}
			else if (user_input == "종료") {
				cout << "종료합니다.";
				break;  // 종료를 입력받으면 종료
			}
			else {
				throw invalid_argument("잘못된 입력입니다.");
			}   // 사용자 입력이 상/하/좌/우/지도/종료 외에 다른 것이라면 잘못된 입력 출력

			// 목적지에 도달했는지 체크
			bool finish = checkGoal(map, player[0]->GetX(), player[0]->GetY(), player[1]->GetX(), player[1]->GetY());
			if (finish == true) {
				cout << "목적지에 도착했습니다! 축하합니다!" << endl;
				cout << "게임을 종료합니다." << endl;  //목적지에 도달했다면 축하메시지 출력 후 종료
				break;
			}

			//체력이 0이 되었는 지 체크
			bool hp_check = CheckUser(player[0], player[1]);
			if (hp_check == false) {
				cout << "실패" << endl;
				cout << "게임을 종료합니다" << endl; //체력이 0이 되면 실패 출력 후 종료
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


// 지도와 사용자 위치 출력하는 함수
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
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}                   // 초반에 설정한 위치대로 아이템,적,포션, 목적지 출력
			}
		}
		cout << endl;
		cout << " ---------------------------------------" << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x1, int user_y1, int user_x2, int user_y2, int mapX, int mapY) {
	bool checkFlag = false;
	if (user_x1 >= 0 && user_x1 < mapX && user_y1 >= 0 && user_y1 < mapY &&
		user_x2 >= 0 && user_x2 < mapX && user_y2 >= 0 && user_y2 < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2) {
	// 목적지 도착하면 true 반환
	if ((map[user_y1][user_x1] == 4) or (map[user_y2][user_x2] == 4)) {
		return true;
	}
	return false;
}


// 포션, 아이템, 적 체크 함수
void checkState(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2, User* player1, User* player2) {
	int posState = map[user_y1][user_x1];
	int posState2 = map[user_y2][user_x2];
	User my_user;
	if ((k % 2) == 0) {
		switch (posState) {
		case 1:
			cout << "아이템이 있습니다" << endl;
			break;
		case 2:
			cout << "적이 있습니다. 체력이 2만큼 깎입니다." << endl;
			player1->DecreaseHP(2); // 체력 2 깎기
			my_user.doAttack();
			player1->doAttack();
			cout << "체력은 " << player1->GetHP() << "입니다." << endl;
			break;
		case 3:
			cout << " 포션이 있습니다. 체력이 2만큼 회복됩니다." << endl;
			player1->increaseHP(2); //체력 2 회복
			cout << "체력은 " << player1->GetHP() << "입니다." << endl;
			break;
		}  // 유저 위치에 아이템, 적, 포션 이 있으면 이를 출력
	}
	if ((k % 2) == 1) {
		switch (posState2) {
		case 1:
			cout << "아이템이 있습니다" << endl;
			break;
		case 2:
			cout << "적이 있습니다. 체력이 2만큼 깎입니다." << endl;
			player2->DecreaseHP(2); // 체력 2 깎기
			my_user.doAttack();
			player2->doAttack();
			cout << "체력은 " << player2->GetHP() << "입니다." << endl;
			break;
		case 3:
			cout << " 포션이 있습니다. 체력이 2만큼 회복됩니다." << endl;
			player2->increaseHP(2); //체력 2 회복
			cout << "체력은 " << player2->GetHP() << "입니다." << endl;
			break;
		}  // 유저 위치에 아이템, 적, 포션 이 있으면 이를 출력
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
		cout << "현재 유저는 Magician 입니다" << endl;
	}
	else if ((k % 2) == 1) {
		cout << "현재 유저는 Warrior 입니다" << endl;
	}
}
