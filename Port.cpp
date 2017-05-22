#include "Port.h"
#include <windows.h>
#include "whirlpoolCard.h"
class Player;

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

void Field::mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector)
{
}


//// ------ Whirpool implementation ------ ////
void Whirlpool::mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector)
{
	int randomNumber = 27;
	while (randomNumber == 27)
		randomNumber = RandomRange(0,35);

	player->movePlayerToSpecificField(randomNumber);
	player->updateCurrentField(fieldsVector->at(randomNumber));
	label->Text = randomNumber;
	if (randomNumber < 10 )
	{
        (static_cast<TwhirlpoolCardFrame*>(cardFramePtr))->number2->SendToBack();
		(static_cast<TwhirlpoolCardFrame*>(cardFramePtr))->number1->ImageIndex = randomNumber;
	}
	else
	{
		int firstNumber = randomNumber / 10;
		int secondNumber = randomNumber % 10;
		(static_cast<TwhirlpoolCardFrame*>(cardFramePtr))->number2->BringToFront();
		(static_cast<TwhirlpoolCardFrame*>(cardFramePtr))->number1->ImageIndex = firstNumber;
		(static_cast<TwhirlpoolCardFrame*>(cardFramePtr))->number2->ImageIndex = secondNumber;
	}
	cardFramePtr->Visible = true;
}

//// ------ Port implementation ------ ////
Port::Port(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr, int conquerCost, int visitingPayment, UnicodeString name, int nation):Field(fieldNumber, fieldImagePtr, cardFramePtr)
{
	this->owner = NULL;
	this->conquerCost = conquerCost;
	this->visitingPayment = visitingPayment;
	this->name = name;
	this->extensionLvl = 1;
	this->portsCardFramePtr = (static_cast<TportsCardFrame*>(cardFramePtr));
    portsCardFramePtr->portRelatedWithCard = this;
	portsCardFramePtr->conquerCostLabel->Text = conquerCost;
	portsCardFramePtr->visitingPaymentLabel->Text = visitingPayment;
	portsCardFramePtr->cityLabel->Text = name;
	portsCardFramePtr->extensionLvlLabel->Text = 1;

	switch (nation)
	{
	case PORTUGAL:
	{
		portsCardFramePtr->flagImage->ImageIndex = 0;
		portsCardFramePtr->writing->ImageIndex = 0;
        break;
	}
	case NETHERLANDS:
	{
		portsCardFramePtr->flagImage->ImageIndex = 1;
		portsCardFramePtr->writing->ImageIndex = 1;
		break;
	}
	case GREAT_BRITAIN:
	{
		portsCardFramePtr->flagImage->ImageIndex = 2;
		portsCardFramePtr->writing->ImageIndex = 2;
		break;
	}
	case FRANCE:
	{
		portsCardFramePtr->flagImage->ImageIndex = 3;
		portsCardFramePtr->writing->ImageIndex = 3;
		break;
	}
	case SPAIN:
	{
		portsCardFramePtr->flagImage->ImageIndex = 4;
		portsCardFramePtr->writing->ImageIndex = 4;
		break;
	}
	default:
        break;
    };
}

int Port::getConquerCost()
{
    return conquerCost;
}

void Port::setOwner(Player *owner)
{
	this->owner = owner;
}

Player* Port::getOwner()
{
   return owner;
}
void Port::setCurrentPlayerLocatedOnField(Player *player)
{
	currentPlayerLocatedOnField = player;
}
Player* Port::getCurrentPlayerLocatedOnField()
{
	return currentPlayerLocatedOnField;
}


void Port::mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector)
{
	label->Text = player->getCurrentFieldPtr()->getFieldNumber();
	currentPlayerLocatedOnField = player;
	cardFramePtr->Visible = true;
}

//// ------ LuckyWind implementation ------ ////
LuckyWind::LuckyWind(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr, unsigned int *iterator):Field(fieldNumber, fieldImagePtr, cardFramePtr)
{
	this->iterator = iterator;
}

void LuckyWind::mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector)
{
	label->Text = *iterator;
	--(*(this->iterator));

}

//// ------ Shallow implementation ------ ////
void Shallow::mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector)
{
	player->forbidPlayerForMoveInNextTurn();
}

//// ------ Storm implementation ------ ////
void Storm::mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector)
{
	player->forbidPlayerForMoveInNextTurn();
}

