#include <iostream>
#include <string>
using namespace std;

class User
{	
	
private:
	int hp;//ü��

public:
	void DecreaseHP(int dec_hp);//HP ���� ����Լ�
	void increaseHP(int inc_hp);//HP ���� ����Լ�
	int GetHP();//ü�� ��ȯ �Լ�
	//ü�� 20���� �ʱ�ȭ
	User() {
		hp = 20;
	}
	User(int h) {
		hp = h;
	}
};

