#include "gameLib.h"
#include <windows.h>
Player::Player(string _name, int _ownedMoney, TImage *_playerImagePtr, TFloatAnimation *_moveInXAxis, TFloatAnimation *_moveInYAxis)
{
	name = _name;
	ownedMoney = _ownedMoney;
	playerImagePtr = _playerImagePtr;
	playerFlowAnimationX =  _moveInXAxis;
	playerFlowAnimationY =  _moveInYAxis;

}

void Player::setName(string _name)
{
    name = _name;
}

void Player::movePlayer(int fieldToMove)
{
	//for(int i=0; i<fieldToMove; i++)
	//{
		playerFlowAnimationX->Duration *= fieldToMove;
		playerFlowAnimationY->Duration *= fieldToMove;
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X - (fieldToMove*88);
	   //	playerImagePtr->Position->X = playerFlowAnimationX->StopValue;
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y + (fieldToMove*50);
	  //	playerImagePtr->Position->Y = playerFlowAnimationY->StopValue;
		playerFlowAnimationX->Start();
		playerFlowAnimationY->Start();
	//}
}

/// ----- F I E L D implementation ------ ////

Field::Field(int _fieldNumber, TImage *_fieldImagePtr)
{
	fieldNumber = _fieldNumber;
	fieldImagePtr = _fieldImagePtr;
}
