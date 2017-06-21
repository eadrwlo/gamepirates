//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <ctime>
#include "frameMap.h"
#include "whirlpoolCard.h"
#include "pirateShipCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "playerStatisticsBox"
#pragma resource "*.fmx"

Tframe1Map *frame1Map;
bool isLastLoopIteration = false;
bool moves = false;
bool buttonThowState = false;

//---------------------------------------------------------------------------
__fastcall Tframe1Map::Tframe1Map(TComponent* Owner)
	: TFrame(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall Tframe1Map::startStopThrowingClick(TObject *Sender)
{
	timerForDice->Enabled = !(timerForDice->Enabled);
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::timerForDiceTimer(TObject *Sender)
{

		drawnNumber++;
		dice->ImageIndex = drawnNumber - 1;
		if (drawnNumber == 7)
		{
			drawnNumber = 1;
			dice->ImageIndex = drawnNumber - 1;
		}
		//Label1->Text = drawnNumber;
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::groundMovementTimer(TObject *Sender)
{
	if( moves == false)
	{
		background->Position->X +=3;
		moves = true;
	}
	else
	{
		background->Position->X -=3;
		moves = false;
	}
}
//---------------------------------------------------------------------------

void Tframe1Map::fillFieldsVectorWithFields()
{
	this->fieldsVector.push_back(new Field(0, this->field00));
	this->fieldsVector.push_back(new Port(1, this->field01, new TportsCardFrame(this, 1), 100, 25, "Haga", NETHERLANDS));
	this->fieldsVector.push_back(new Field(2, this->field02));
	this->fieldsVector.push_back(new Port(3, this->field03, new TportsCardFrame(this, 3), 100, 25, "Domburg", NETHERLANDS));
	this->fieldsVector.push_back(new Port(4, this->field04, new TportsCardFrame(this, 4), 100, 25, "Den Helder", NETHERLANDS));
	this->fieldsVector.push_back(new Field(5, this->field05));
	this->fieldsVector.push_back(new Port(6, this->field06, new TportsCardFrame(this, 6), 100, 25, "Maasvlakte Rotterdam", NETHERLANDS));
	this->fieldsVector.push_back(new Field(7, this->field07));
	this->fieldsVector.push_back(new PirateShip(8, this->field08, new TpirateShipCardFrame(this, 1)));
	this->fieldsVector.push_back(new LuckyWind(9, this->field09, NULL, &iterator));
	this->fieldsVector.push_back(new Port(10, this->field10, new TportsCardFrame(this, 10), 100, 25, "Barcelona", SPAIN));
	this->fieldsVector.push_back(new Field(11, this->field11));
	this->fieldsVector.push_back(new Port(12, this->field12, new TportsCardFrame(this, 11), 100, 25, "Valencia", SPAIN));
	this->fieldsVector.push_back(new Field(13, this->field13));
	this->fieldsVector.push_back(new Port(14, this->field14, new TportsCardFrame(this, 14), 100, 25, "Bilbao", SPAIN));
	this->fieldsVector.push_back(new Port(15, this->field15, new TportsCardFrame(this, 15), 100, 25, "Las Palmas", SPAIN));
	this->fieldsVector.push_back(new Field(16, this->field16));
	this->fieldsVector.push_back(new Shallow(17, this->field17, NULL));
	this->fieldsVector.push_back(new Field(18, this->field18));
	this->fieldsVector.push_back(new Port(19, this->field19, new TportsCardFrame(this, 19), 100, 25, "Brington", GREAT_BRITAIN));
	this->fieldsVector.push_back(new Port(20, this->field20, new TportsCardFrame(this, 20), 100, 25, "London", GREAT_BRITAIN));
	this->fieldsVector.push_back(/*new Field(21, this->field21)*/new PirateShip(21, this->field21, new TpirateShipCardFrame(this, 2)));
	this->fieldsVector.push_back(new Port(22, this->field22, new TportsCardFrame(this, 22), 100, 25, "Southampton", GREAT_BRITAIN));
	this->fieldsVector.push_back(new Port(23, this->field23, new TportsCardFrame(this, 23), 100, 25, "Belfast", GREAT_BRITAIN));
	this->fieldsVector.push_back(new Field(24, this->field24));
	this->fieldsVector.push_back(new Port(25, this->field25, new TportsCardFrame(this, 25), 100, 25, "Bordeaux", FRANCE));
	this->fieldsVector.push_back(new Port(26, this->field26, new TportsCardFrame(this, 26), 100, 25, "Calais", FRANCE));
	this->fieldsVector.push_back(new Whirlpool(27, this->field27, new TwhirlpoolCardFrame(this)));
	this->fieldsVector.push_back(new Port(28, this->field28, new TportsCardFrame(this, 28), 100, 25, "Marsylia", FRANCE));
	this->fieldsVector.push_back(new Port(29, this->field29, new TportsCardFrame(this, 29), 100, 25, "Montpellier", FRANCE));
	this->fieldsVector.push_back(new Field(30, this->field30));
	this->fieldsVector.push_back(new Port(31, this->field31, new TportsCardFrame(this, 31), 100, 25, "Lizbona", PORTUGAL));
	this->fieldsVector.push_back(new Storm(32, this->field32, NULL));
	this->fieldsVector.push_back(new Port(33, this->field33, new TportsCardFrame(this, 33), 100, 25, "Setubal", PORTUGAL));
	this->fieldsVector.push_back(new Port(34, this->field34, new TportsCardFrame(this, 34), 100, 25, "Madera", PORTUGAL));
	this->fieldsVector.push_back(new Port(35, this->field35, new TportsCardFrame(this, 35), 100, 25, "Vania do Castelo", PORTUGAL));
}

// ************************************
// Funnkcja timera przesuwająca gracza.
// Każde wyzwolenie funkcji (wlączenie timera) timerForPlayerMovementExecuteTimer przesuwa gracza o jedno pole.
// Funkcja "sama" zatrzymuje timer który nią steruje w momencie kiedy wykona sie odpowiednią ilość razy tzn
// przesunie gracza o wyrzuconą licznbę oczek.
// *************************************

void __fastcall Tframe1Map::timerForPlayerMovementExecuteTimer(TObject *Sender)
{
	if (!isLastLoopIteration)
	{
		players[indexOfPlayer]->movePlayerToNeighbouringFiedl();
		if ((players[indexOfPlayer]->getCurrentFieldPtr())->getFieldNumber() == 35)
		{
			players[indexOfPlayer]->updateCurrentField(this->fieldsVector[0]);
		}
		else
		{
			players[indexOfPlayer]->updateCurrentField(this->fieldsVector[(players[indexOfPlayer]->getCurrentFieldPtr())->getFieldNumber()+1]);
		}

		fieldsCounter ++;
		if (fieldsCounter == drawnNumber)
		{
			isLastLoopIteration = true;
			fieldsCounter = 0;
		}
	}
	else
	{
		//Label1->Text = players[indexOfPlayer]->getCurrentFieldPtr()->getFieldNumber();
		this->fieldsVector[(players[indexOfPlayer]->getCurrentFieldPtr()->getFieldNumber())]->mainEventWhenPlayerIsOnTheField(players[indexOfPlayer], Label1, &(this->fieldsVector));
		timerForPlayerMovementExecute->Enabled = false;
		isLastLoopIteration = false;
        if(this->fieldsVector[(players[indexOfPlayer]->getCurrentFieldPtr()->getFieldNumber())]->cardFramePtr == 0)
		{
			frame1Map->players[(frame1Map->indexOfPlayer) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=false;
			frame1Map->players[(frame1Map->indexOfPlayer+1) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=true;
		}
	}

	Label1->Text = players[indexOfPlayer]->getCurrentFieldPtr()->getFieldNumber();
	//Label1->Text = RandomRange(0,35);
}
//---------------------------------------------------------------------------


void __fastcall Tframe1Map::CornerButton1Click(TObject *Sender)
{
	//Label1->Text = drawnNumber;
	timerForDice->Enabled = !(timerForDice->Enabled);
	if(buttonThowState == false)
	{
		CornerButton1->Text = "Zatrzymaj kostke !";
		buttonThowState = !(buttonThowState);
	}
	else if (buttonThowState)
	{
		CornerButton1->Text = "Rzuc kostka !";
		buttonThowState = !(buttonThowState);
    }

}
//---------------------------------------------------------------------------


void __fastcall Tframe1Map::CornerButton2Click(TObject *Sender)
{
	indexOfPlayer = (iterator % numberOfPlayers);
	if(playersWhoAreStillInGame[indexOfPlayer])
	{
		if((players[indexOfPlayer]->getPermissionToMove()) == 0)
		{
			players[indexOfPlayer]->allowPlayerForMoveInNextTurn();
			iterator++;
			indexOfPlayer = (iterator % numberOfPlayers);
			timerForPlayerMovementExecute->Enabled = true;
			iterator++;
		}
		else
		{
			players[indexOfPlayer]->rebuildStrenghtAttack();
			timerForPlayerMovementExecute->Enabled = true;
			iterator++;	
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::playerStatisticsBoxFrame1Click(TObject *Sender)
{
	Visible = false;
}
//---------------------------------------------------------------------------
/*
void __fastcall Tframe1Map::playerStatisticsBoxFrame1boxImageMouseEnter(TObject *Sender)

{
	playerStatisticsBoxFrame1->Position->X = 0;
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::playerStatisticsBoxFrame1boxImageMouseLeave(TObject *Sender)

{
	playerStatisticsBoxFrame1->Position->X = -360;
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::playerStatisticsBoxFrame2boxImageMouseEnter(TObject *Sender)

{
	 playerStatisticsBoxFrame2->Position->X = 1550;
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::playerStatisticsBoxFrame2boxImageMouseLeave(TObject *Sender)

{
	playerStatisticsBoxFrame2->Position->X = 1907;
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::playerStatisticsBoxFrame3boxImageMouseEnter(TObject *Sender)

{
	playerStatisticsBoxFrame3->Position->X = 1550;
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::playerStatisticsBoxFrame3boxImageMouseLeave(TObject *Sender)

{
	playerStatisticsBoxFrame3->Position->X = 1907;
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::playerStatisticsBoxFrame4boxImageMouseEnter(TObject *Sender)

{
	playerStatisticsBoxFrame4->Position->X = 0;
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::playerStatisticsBoxFrame4boxImageMouseLeave(TObject *Sender)

{
    playerStatisticsBoxFrame4->Position->X = -360;
}
//---------------------------------------------------------------------------
*/



