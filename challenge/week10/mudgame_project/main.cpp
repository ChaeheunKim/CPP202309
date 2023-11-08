#include <iostream>
#include <string>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5; // 게임이 진행될 배열 설정


// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
bool checkhp(int hp);
void checkState(int map[][mapX], int user_x, int user_y);
User my_user;



// 메인  함수
int main() {
	my_user.hp = 20;//사용자 체력 20 설정
	
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} }; // 아이템,포션, 목적지 위치 설정

	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호   // 유저 위치를 맨 처음으로 설정

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;   //사용자에게 입력받기

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;  // 유저가 맵 안에 없다면 경고 출력
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				my_user.DecreaseHP(1); // 이동으로 체력 한 칸 감소
				displayMap(map, user_x, user_y); // 위로 올라간 상태 저장
				cout << "체력은 " << my_user.GetHP() << "입니다"<<endl; //남은 체력 출력
				checkState(map, user_x, user_y); //적, 포션, 아이템 만났을 때 함수
			} 
		}
		else if (user_input == "하") {
			// 아래로 한 칸 내려가기
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1; // 유저가 맵 안에 없다면 경고 출력
			}
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				my_user.DecreaseHP(1); // 이동으로 체력 한 칸 감소
				displayMap(map, user_x, user_y);  // 아래로 한 칸 내려간 상태 저장
				cout << "체력은 " << my_user.GetHP() << "입니다"<<endl; //남은 체력 출력
				checkState(map, user_x, user_y); //적, 포션, 아이템 만났을 때 함수
			}   
		}
		else if (user_input == "좌") {
			// 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1; // 유저가 맵 안에 없다면 경고 출력
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				my_user.DecreaseHP(1); // 이동으로 체력 한 칸 감소
				displayMap(map, user_x, user_y); // 왼쪽로 한 칸 간 상태 저장
				cout << "체력은 " << my_user.GetHP() << "입니다" << endl;; //남은 체력 출력
				checkState(map, user_x, user_y); //적, 포션, 아이템 만났을 때 함수
			}  
		}
		else if (user_input == "우") {
			// 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1; // 유저가 맵 안에 없다면 경고 출력
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				my_user.DecreaseHP(1); // 이동으로 체력 한 칸 감소
				displayMap(map, user_x, user_y); // 오른쪽로 한 칸 간 상태 저장
				cout << "체력은 " << my_user.GetHP() << "입니다" << endl;; //남은 체력 출력
				checkState(map, user_x, user_y); //적, 포션, 아이템 만났을 때 함수
			}   
		} 
		else if (user_input == "지도") {
			// 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;  // 종료를 입력받으면 종료
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}   // 사용자 입력이 상/하/좌/우/지도/종료 외에 다른 것이라면 잘못된 입력 출력

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;  //목적지에 도달했다면 축하메시지 출력 후 종료
			break;
		}

		//체력이 0이 되었는 지 체크
		bool hp_check = checkhp(my_user.GetHP());
		if (hp_check == true) {
			cout << "실패" << endl;
			cout << "게임을 종료합니다" << endl; //체력이 0이 되면 실패 출력 후 종료
			break;
		}

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
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
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면 true 반환
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 체력을 다 했는 지 체크하는 함수
bool checkhp(int hp) {
	if (hp <= 0) {  //체력이 0이히면 true 반환
		return true;
	}
	return false;
}

// 포션, 아이템, 적 체크 함수
void checkState(int map[][mapX], int user_x, int user_y) {
			int posState = map[user_y][user_x];

				switch (posState) {
				case 1:
					cout << "아이템이 있습니다"<<endl;
					break;
				case 2:
					cout << "적이 있습니다. 체력이 2만큼 깎입니다."<<endl;
					my_user.DecreaseHP(2);  // 체력 2 깎기
					cout << "체력은 " << my_user.hp <<"입니다."<<  endl;
					break;
				case 3:
					cout << " 포션이 있습니다. 체력이 2만큼 회복됩니다."<<endl;
					my_user.hp = my_user.hp + 2; //체력 2 회복
					cout << "체력은 " << my_user.hp << "입니다."<< endl;
					break;
				}  // 유저 위치에 아이템, 적, 포션 이 있으면 이를 출력
		}