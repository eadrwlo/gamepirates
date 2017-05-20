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
	this->conquerCost = conquerCost;
	this->visitingPayment = visitingPayment;
	this->name = name;
	this->extensionLvl = 1;
	this->portsCardFramePtr = (static_cast<TportsCardFrame*>(cardFramePtr));
	portsCardFramePtr->conquerCostLabel->Text = conquerCost;
	portsCardFramePtr->visitingPaymentLabel->Text = visitingPayment;
	portsCardFramePtr->cityLabel->Text = name;
	//portsCardFramePtr->extensionLvlLabel->Text = 1;

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

void Port::mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector)
{
	currentPlayerLocatedOnField = player;
	cardFramePtr->Visible = true;

}



