#include "user.h"

int User::GetHP()
{
	return hp;
}
void User::DecreaseHP(int dec_hp)
{
	hp = hp - dec_hp;
}