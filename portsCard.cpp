//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "portsCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
//TportsCardFrame *portsCardFrame;
//---------------------------------------------------------------------------
__fastcall TportsCardFrame::TportsCardFrame(TComponent* Owner, int cardNumber)
	: TFrame(Owner)
{
	UnicodeString newName = this->Name;
	newName = newName.operator +=(UnicodeString(cardNumber));
	this->Name = newName;
    this->Parent = static_cast<TFrame*>(Owner);
	this->Visible = false;
	this->Position->X = 750;
	this->Position->Y = 220;
}
//---------------------------------------------------------------------------
void __fastcall TportsCardFrame::payButtonClick(TObject *Sender)
{
	Visible = false;
}

//Player* TportsCardFrame::getOwnerOfRelatedPort()
//{
//	return ownerOfRelatedPort;
//}
//void TportsCardFrame::setCurrentlyOperatedPlayer(Player *player)
//{
//	currentlyOperatedPlayer = player;
//}

//---------------------------------------------------------------------------
void __fastcall TportsCardFrame::conquerButtonClick(TObject *Sender)
{
	if (portRelatedWithCard->getCurrentPlayerLocatedOnField() != portRelatedWithCard->getOwner()) // Czy port nie jest gracza ktory na nim stanal?
	{
		if (portRelatedWithCard->getCurrentPlayerLocatedOnField()->getOwnedMoney() > portRelatedWithCard->getConquerCost())
		{
			portRelatedWithCard->setOwner(portRelatedWithCard->getCurrentPlayerLocatedOnField());
			ownerLabel->Text = portRelatedWithCard->getOwner()->getName();
		}
	}
	Visible = false;
}
//---------------------------------------------------------------------------

