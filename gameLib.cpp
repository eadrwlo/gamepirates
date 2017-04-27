#include "gameLib.h"
#include <windows.h>
#include "whirlpoolCard.h"
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


void Player::movePlayerToSpecificField(int fieldNumber)
{
	if (fieldNumber == 1)
	{
		playerImagePtr->Position->X += (87 * 9);
		playerImagePtr->Position->Y += (50 * 9);
	}
	else if (fieldNumber < 28 && fieldNumber > 18)
	{
	   playerImagePtr->Position->X -= (87 * (currentFieldPtr->getFieldNumber() - fieldNumber));
	   playerImagePtr->Position->Y += (50 * (currentFieldPtr->getFieldNumber() - fieldNumber));
	}
	else if (fieldNumber > 28 && fieldNumber <= 36)
	{
		playerImagePtr->Position->X += (87 * (fieldNumber - currentFieldPtr->getFieldNumber()));
		playerImagePtr->Position->Y += (50 * (fieldNumber - currentFieldPtr->getFieldNumber()));
	}
	else if (fieldNumber > 9 && fieldNumber <=18)
	{
		playerImagePtr->Position->X -= (87 * 9);
		playerImagePtr->Position->Y += (50 * 9);
		playerImagePtr->Position->X += (87 * (19 - fieldNumber));
		playerImagePtr->Position->Y += (50 * (19 - fieldNumber));
	}
	else if (fieldNumber > 1 && fieldNumber <10)
	{
		playerImagePtr->Position->X += (87 * 9);
		playerImagePtr->Position->Y += (50 * 9);
		playerImagePtr->Position->X -= (87 * (fieldNumber-1));
		playerImagePtr->Position->Y += (50 * (fieldNumber-1));
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

//// ----- F I E L D implementation ------ ////

Field::Field(int fieldNumber, TImage *fieldImagePtr)
{
	this->fieldNumber = fieldNumber;
	this->fieldImagePtr = fieldImagePtr;
}

Field::Field(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr)
{
	this->fieldNumber = fieldNumber;
	this->fieldImagePtr = fieldImagePtr;
	this->cardFramePtr = cardFramePtr;
}


int Field::getFieldNumber()
{
    return fieldNumber;
}

void Field::mainEventWhenPlayerIsOnTheField(Player *player)
{
}


//// ------ Whirpool implementation ------ ////
void Whirlpool::mainEventWhenPlayerIsOnTheField(Player *player)
{
	//srand( time( NULL ) );
	//int randomNumber = (rand()%36)+1;
	int randomNumber = 19;
	int firstNumber = randomNumber / 10;
	int secondNumber = randomNumber % (firstNumber * 10);
	cardFramePtr->Visible = true;
	(static_cast<TwhirlpoolCardFrame*>(cardFramePtr))->number1->ImageIndex = firstNumber;
	(static_cast<TwhirlpoolCardFrame*>(cardFramePtr))->number2->ImageIndex = secondNumber;
	player->movePlayerToSpecificField(randomNumber);
}





