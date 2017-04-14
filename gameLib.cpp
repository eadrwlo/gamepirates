#include "gameLib.h"
#include <windows.h>
Player::Player(string _name, int _ownedMoney, TImage *_playerImagePtr, TFloatAnimation *_moveInXAxis, TFloatAnimation *_moveInYAxis, Field *_currentFieldPtr)
{
	name = _name;
	ownedMoney = _ownedMoney;
	playerImagePtr = _playerImagePtr;
	playerFlowAnimationX =  _moveInXAxis;
	playerFlowAnimationY =  _moveInYAxis;
	currentFieldPtr = _currentFieldPtr;
}

void Player::setName(string _name)
{
	name = _name;
}

void Player::movePlayer(int fieldToMove)
{
	if ( currentFieldPtr->getFieldNumber() < 10 )
	{
		// to do - gracz jest na boku mapy -- poludnie - zachod
	}
	else if ( currentFieldPtr->getFieldNumber() < 19 )
	{
		// to do - gracz jest na boku mapy -- polnoc - zachod
	}
	else if ( currentFieldPtr->getFieldNumber() < 28 )
	{
		// to do - gracz jest na boku mapy -- polnoc - wschod
	}
	else
	{
		// to do - gracz jest na boku mapy -- poludnie - wschod
	}

		playerFlowAnimationX->Duration = fieldToMove;
		playerFlowAnimationY->Duration = fieldToMove;
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X - (fieldToMove*88);
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y + (fieldToMove*50);
		playerFlowAnimationX->Start();
		playerFlowAnimationY->Start();

}

/// ----- F I E L D implementation ------ ////

Field::Field(int _fieldNumber, TImage *_fieldImagePtr)
{
	fieldNumber = _fieldNumber;
	fieldImagePtr = _fieldImagePtr;
}

int Field::getFieldNumber()
{
    return fieldNumber;
}
