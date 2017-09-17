//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "portsCard.h"
#include "frameMap.h"
#include "Unit1.h"
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
//---------------------------------------------------------------------------//Player* TportsCardFrame::getOwnerOfRelatedPort()
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
	if (portRelatedWithCard->getOwner() == NULL) // Czy port jest wolny?
	{
		if (portRelatedWithCard->getCurrentPlayerLocatedOnField()->getOwnedMoney() >= portRelatedWithCard->getConquerCost()) // Czy gracza stac na port?
		{
			portRelatedWithCard->setOwner(portRelatedWithCard->getCurrentPlayerLocatedOnField());
			portRelatedWithCard->getOwner()->setOwnedMoney(portRelatedWithCard->getOwner()->getOwnedMoney() - portRelatedWithCard->getConquerCost());
			ownerLabel->Text = portRelatedWithCard->getOwner()->getName();
			frame1Map->players[(frame1Map->indexOfPlayer) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=false;
			frame1Map->players[(frame1Map->indexOfPlayer+1) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=true;
			shoutDownCard();
		}
	}
	else
	{
		if (portRelatedWithCard->getCurrentPlayerLocatedOnField()->getAttackStrength() == portRelatedWithCard->getOwner()->getAttackStrength())
		{
			conquerPortMiniGameForm->runConquerPortMiniGame(portRelatedWithCard->getOwner(), portRelatedWithCard->getCurrentPlayerLocatedOnField(), this);
		}
		else
		{
			payButton->Position->X = 150;
			payButton->Position->Y = 350;
			payButton->Visible = true;
			questionBox->Visible = true;
			payButton->BringToFront();
			notEnoughtsStrenghtStatementImg->Visible = true;
        }
	}

}
//---------------------------------------------------------------------------

void __fastcall TportsCardFrame::payButtonClick(TObject *Sender)
{
	portRelatedWithCard->getOwner()->setOwnedMoney(portRelatedWithCard->getOwner()->getOwnedMoney() + portRelatedWithCard->getVisitingPayment());
	portRelatedWithCard->getCurrentPlayerLocatedOnField()->setOwnedMoney(portRelatedWithCard->getCurrentPlayerLocatedOnField()->getOwnedMoney() - portRelatedWithCard->getVisitingPayment());
	frame1Map->players[(frame1Map->indexOfPlayer) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=false;
	frame1Map->players[(frame1Map->indexOfPlayer+1) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=true;
	shoutDownCard();
}
//---------------------------------------------------------------------------

 void TportsCardFrame::shoutDownCard()
 {
	payButton->Visible = false;
	payButton->Position->X = 48;
	payButton->Position->Y = 424;
	conquerButton->Visible = false;
	buildButton->Visible = false;
	closeButton->Visible = false;
    notEnoughtsStrenghtStatementImg->Visible = false;
	Visible = false;
 }
void __fastcall TportsCardFrame::closeButtonClick(TObject *Sender)
{
    frame1Map->players[(frame1Map->indexOfPlayer) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=false;
	frame1Map->players[(frame1Map->indexOfPlayer+1) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=true;
    shoutDownCard();
}
//---------------------------------------------------------------------------

void __fastcall TportsCardFrame::buildButtonClick(TObject *Sender)
{
    frame1Map->players[(frame1Map->indexOfPlayer) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=false;
	frame1Map->players[(frame1Map->indexOfPlayer+1) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=true;
    shoutDownCard();
}
//---------------------------------------------------------------------------

