#include "gameLib.h"

Player::Player(string _name, int _ownedMoney, TImage *playerImagePtr)
{
	name = "noName";
	ownedMoney = _ownedMoney;
}

void Player::setName(string _name)
{
    name = _name;
}
