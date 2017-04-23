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

void Player::movePlayer(int drawnNumber)
{
	if ( currentFieldPtr->getFieldNumber() < 10 )
	{
		// to do - gracz jest na boku mapy -- poludnie - zachod
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X - 88;
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y + 50;
	}
	else if ( currentFieldPtr->getFieldNumber() < 19 )
	{
		// to do - gracz jest na boku mapy -- polnoc - zachod
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X - 88;
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y - 50;
	}
	else if ( currentFieldPtr->getFieldNumber() < 28 )
	{
		// to do - gracz jest na boku mapy -- polnoc - wschod
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X + 88;
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y - 50;
	}
	else
	{
		// to do - gracz jest na boku mapy -- poludnie - wschod
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X + 88;
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y + 50;
	}
	playerFlowAnimationX->Start();
	playerFlowAnimationY->Start();
}

void Player::updateCurrentField(Field *newFieldPtr)
{
   currentFieldPtr = newFieldPtr;
}

Field* Player::getCurrentFieldPtr()
{
	return currentFieldPtr;
}

//// ----- F I E L D implementation ------ ////

Field::Field(int fieldNumber, TImage *fieldImagePtr)
{
	this->fieldNumber = fieldNumber;
	this->fieldImagePtr = fieldImagePtr;
}

Field::Field(int fieldNumber, TImage *fieldImagePtr, TImage *cardImagePtr)
{
	this->fieldNumber = fieldNumber;
	this->fieldImagePtr = fieldImagePtr;
    this->cardImagePtr = cardImagePtr;
}


int Field::getFieldNumber()
{
    return fieldNumber;
}

void Field::mainEventWhenPlayerIsOnTheField()
{
}


//// ------ Whirpool implementation ------ ////
void Whirpool::mainEventWhenPlayerIsOnTheField()
{
	this->cardImagePtr->Visible = true;
}





