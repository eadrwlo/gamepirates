#include "player.h"

Player::Player(UnicodeString _name, int _ownedMoney, TImage *_playerImagePtr, TFloatAnimation *_moveInXAxis, TFloatAnimation *_moveInYAxis, Field *_currentFieldPtr)
{
	name = _name;
	ownedMoney = _ownedMoney;
	playerImagePtr = _playerImagePtr;
	playerFlowAnimationX =  _moveInXAxis;
	playerFlowAnimationY =  _moveInYAxis;
	currentFieldPtr = _currentFieldPtr;
	permissionToMoveInCurrentTurn = 1;
}

void Player::setName (UnicodeString _name)
{
	name = _name;
}

void Player::movePlayerToNeighbouringFiedl()
{
	if ( currentFieldPtr->getFieldNumber() < 9 )
	{
		// to do - gracz jest na boku mapy -- poludnie - zachod
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X - 88;
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y + 50;
	}
	else if ( currentFieldPtr->getFieldNumber() < 18 )
	{
		// to do - gracz jest na boku mapy -- polnoc - zachod
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X - 88;
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y - 50;
	}
	else if ( currentFieldPtr->getFieldNumber() < 27 )
	{
		// to do - gracz jest na boku mapy -- polnoc - wschod
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X + 88;
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y - 50;
	}
	else if ( currentFieldPtr->getFieldNumber() < 36 )
	{
		// to do - gracz jest na boku mapy -- poludnie - wschod
		playerFlowAnimationX->StopValue = playerImagePtr->Position->X + 88;
		playerFlowAnimationY->StopValue = playerImagePtr->Position->Y + 50;
	}
	playerFlowAnimationX->Start();
	playerFlowAnimationY->Start();
}


void Player::movePlayerToSpecificField(int fieldNumber)
{
	if (fieldNumber == 0)
	{
		playerImagePtr->Position->X += (87 * 9);
		playerImagePtr->Position->Y += (50 * 9);
	}
	else if (fieldNumber < 27 && fieldNumber > 18)
	{
	   playerImagePtr->Position->X -= (87 * (currentFieldPtr->getFieldNumber() - fieldNumber));
	   playerImagePtr->Position->Y += (50 * (currentFieldPtr->getFieldNumber() - fieldNumber));
	}
	else if (fieldNumber > 27 && fieldNumber <= 35)
	{
		playerImagePtr->Position->X += (87 * (fieldNumber - currentFieldPtr->getFieldNumber()));
		playerImagePtr->Position->Y += (50 * (fieldNumber - currentFieldPtr->getFieldNumber()));
	}
	else if (fieldNumber > 8 && fieldNumber <=17)
	{
		playerImagePtr->Position->X -= (87 * 9);
		playerImagePtr->Position->Y += (50 * 9);
		playerImagePtr->Position->X += (87 * (18 - fieldNumber));
		playerImagePtr->Position->Y += (50 * (18 - fieldNumber));
	}
	else if (fieldNumber > 0 && fieldNumber < 9)
	{
		playerImagePtr->Position->X += (87 * 9);
		playerImagePtr->Position->Y += (50 * 9);
		playerImagePtr->Position->X -= 87 * fieldNumber;
		playerImagePtr->Position->Y += 50 * fieldNumber;
    }

}



void Player::updateCurrentField(Field *newFieldPtr)
{
   currentFieldPtr = newFieldPtr;
}

Field* Player::getCurrentFieldPtr()
{
	return currentFieldPtr;
}

int Player::getPermissionToMove()
{
	return permissionToMoveInCurrentTurn;
}

void Player::allowPlayerForMoveInNextTurn()
{
	permissionToMoveInCurrentTurn = 1;
}

void Player::forbidPlayerForMoveInNextTurn()
{
	permissionToMoveInCurrentTurn = 0;
}