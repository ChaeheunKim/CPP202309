#include <iostream>
#include <string>
using namespace std;

class User
{protected:
	int user_x;
	int user_y;

private:
	int hp;//체력
	string CurrentUser; //현재 유저


public:
	void DecreaseHP(int dec_hp);//HP 감소 멤버함수
	void increaseHP(int inc_hp);//HP 증가 멤버함수
	virtual void doAttack();//공격 출력 함수
	void SetY(int y);//움직인 위치 저장
	void SetX(int x);//움직인 위치 저장
	int GetHP(); //체력 가져오기
	int GetX(); //X 위치 가져오기
	int GetY(); //Y 위치 가져오기
	User() {
		hp = 20;
	}
	User(int h) {
		hp = h;
	}
	
};

class Magician : public User {
public:
	Magician() {
		// Magician 클래스의 생성자에서 user_x와 user_y 초기화
		user_x = 0; // 초기 x 위치
		user_y = 0; // 초기 y 위치
	}
	void doAttack() override;
};
class Warrior : public User {
public:
	Warrior() {
		// Warrior 클래스의 생성자에서 user_x와 user_y 초기화
		user_x = 0; // 초기 x 위치
		user_y = 0; // 초기 y 위치
	}
	void doAttack() override;

};

