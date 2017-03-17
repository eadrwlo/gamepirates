#include "gameLib.h"

Player::Player(string _name, int _ownedMoney, TImage *playerImagePtr)
{
	name = "noName";
	ownedMoney = _ownedMoney;
	currentPositionOnMap.X = 0;
	currentPositionOnMap.Y = 0;
	currentPositionOnMap.fieldNumber = 0;

}

void Player::setName(string _name)
{
    name = _name;
}
