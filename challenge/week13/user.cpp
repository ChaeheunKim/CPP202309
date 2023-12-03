#include "user.h"
int User::GetHP()
{
	return hp;
}
void User::DecreaseHP(int dec_hp)
{
	hp = hp - dec_hp;
}
void User::increaseHP(int inc_hp) {
	hp = hp + inc_hp;
}
void User::doAttack() {
	cout << "공격합니다" << endl;
}
void Magician::doAttack() {
	cout << "마법 사용" << endl;
}
void Warrior::doAttack() {
	cout << "베기 사용" << endl;
}

int User::GetX() {
	return user_x;
}
int User::GetY() {
	return user_y;
}
void User::SetY(int y) {
	user_y = y;
}
void User::SetX(int x) {
	user_x = x;
}