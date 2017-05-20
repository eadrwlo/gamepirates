#include "Port.h"
#include <windows.h>
#include "whirlpoolCard.h"
#include "commonCard.h"
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
	(static_cast<TcommonCardFrame*>(cardFramePtr))->conquerCostLabel->Text = conquerCost;
	(static_cast<TcommonCardFrame*>(cardFramePtr))->visitingPaymentLabel->Text = visitingPayment;
	(static_cast<TcommonCardFrame*>(cardFramePtr))->cityLabel->Text = name;
	(static_cast<TcommonCardFrame*>(cardFramePtr))->extensionLvlLabel->Text = 1;
}

void Port::mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector)
{
	currentPlayerLocatedOnField = player;
	cardFramePtr->Visible = true;

}


