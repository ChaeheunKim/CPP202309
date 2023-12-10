#include <iostream>
#include <string>
using namespace std;

class User
{protected:
	int user_x;
	int user_y;

private:
	int hp;//ü��
	string CurrentUser; //���� ����


public:
	void DecreaseHP(int dec_hp);//HP ���� ����Լ�
	void increaseHP(int inc_hp);//HP ���� ����Լ�
	virtual void doAttack();//���� ��� �Լ�
	void SetY(int y);//������ ��ġ ����
	void SetX(int x);//������ ��ġ ����
	int GetHP(); //ü�� ��������
	int GetX(); //X ��ġ ��������
	int GetY(); //Y ��ġ ��������
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
		// Magician Ŭ������ �����ڿ��� user_x�� user_y �ʱ�ȭ
		user_x = 0; // �ʱ� x ��ġ
		user_y = 0; // �ʱ� y ��ġ
	}
	void doAttack() override;
};
class Warrior : public User {
public:
	Warrior() {
		// Warrior Ŭ������ �����ڿ��� user_x�� user_y �ʱ�ȭ
		user_x = 0; // �ʱ� x ��ġ
		user_y = 0; // �ʱ� y ��ġ
	}
	void doAttack() override;

};

