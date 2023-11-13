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
