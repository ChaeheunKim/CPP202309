#include <iostream>
#include <string>
using namespace std;

class User
{	
	
private:
	int hp;//체력

public:
	void DecreaseHP(int dec_hp);//HP 감소 멤버함수
	void increaseHP(int inc_hp);//HP 증가 멤버함수
	int GetHP();//체력 반환 함수
	//체력 20으로 초기화
	User() {
		hp = 20;
	}
	User(int h) {
		hp = h;
	}
};

