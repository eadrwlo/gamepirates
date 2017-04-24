//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <ctime>
#include "frameMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

Tframe1Map *frame1Map;
Player *player1_1;
bool moves = false;
bool buttonThowState = false;
//---------------------------------------------------------------------------
__fastcall Tframe1Map::Tframe1Map(TComponent* Owner)
	: TFrame(Owner)
{
	drawnNumber = 1;
	fillFieldsVectorWithFields();
	player1_1 = new Player("Adrian", 100, player1, moveInXAxis, moveInYAxis, this->fieldsVector[0]);
}
//---------------------------------------------------------------------------
void __fastcall Tframe1Map::startStopThrowingClick(TObject *Sender)
{
	AnsiString throwTheDice = "Throw the Dice !";
	AnsiString stopTheDice = "Stop the Dice !";
	Label1->Text = drawnNumber;
//	else if (Button1->Text == stopTheDice)
//	{
//		Button1->Text = throwTheDice;
//    }
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
		Label1->Text = drawnNumber;
}
//---------------------------------------------------------------------------


void __fastcall Tframe1Map::przesunClick(TObject *Sender)
{
	fieldsCounter = 0;
	timerForPlayerMovementExecute->Enabled = true;
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
	this->fieldsVector.push_back(new Field(1, this->field01));
	this->fieldsVector.push_back(new Field(2, this->field02));
	this->fieldsVector.push_back(new Field(3, this->field03));
	this->fieldsVector.push_back(new Field(4, this->field04));
	this->fieldsVector.push_back(new Field(5, this->field05));
	this->fieldsVector.push_back(new Field(6, this->field06));
	this->fieldsVector.push_back(new Field(7, this->field07));
	this->fieldsVector.push_back(new Field(8, this->field08));
	this->fieldsVector.push_back(new Field(9, this->field09));
	this->fieldsVector.push_back(new Field(10, this->field10));
	this->fieldsVector.push_back(new Field(11, this->field11));
	this->fieldsVector.push_back(new Field(12, this->field12));
	this->fieldsVector.push_back(new Field(13, this->field13));
	this->fieldsVector.push_back(new Field(14, this->field14));
	this->fieldsVector.push_back(new Field(15, this->field15));
	this->fieldsVector.push_back(new Field(16, this->field16));
	this->fieldsVector.push_back(new Field(17, this->field17));
	this->fieldsVector.push_back(new Field(18, this->field18));
	this->fieldsVector.push_back(new Field(19, this->field19));
	this->fieldsVector.push_back(new Field(20, this->field20));
	this->fieldsVector.push_back(new Field(21, this->field21));
	this->fieldsVector.push_back(new Field(22, this->field22));
	this->fieldsVector.push_back(new Field(23, this->field23));
	this->fieldsVector.push_back(new Field(24, this->field24));
	this->fieldsVector.push_back(new Field(25, this->field25));
	this->fieldsVector.push_back(new Field(26, this->field26));
	this->fieldsVector.push_back(new Field(27, this->field27));
	this->fieldsVector.push_back(new Whirpool(28, this->field28, this->whirpoolCard));
	this->fieldsVector.push_back(new Field(29, this->field29));
	this->fieldsVector.push_back(new Field(30, this->field30));
	this->fieldsVector.push_back(new Field(31, this->field31));
	this->fieldsVector.push_back(new Field(32, this->field32));
	this->fieldsVector.push_back(new Field(33, this->field33));
	this->fieldsVector.push_back(new Field(34, this->field34));
	this->fieldsVector.push_back(new Field(35, this->field35));
	this->fieldsVector.push_back(new Field(36, this->field36));
}




void __fastcall Tframe1Map::timerForPlayerMovementExecuteTimer(TObject *Sender)
{
	player1_1->movePlayer(drawnNumber);
	int currentFieldNumber = (player1_1->getCurrentFieldPtr())->getFieldNumber();
	if (currentFieldNumber == 36)
	{
        player1_1->updateCurrentField(this->fieldsVector[0]);
    }
	else
	{
		player1_1->updateCurrentField(this->fieldsVector[currentFieldNumber]);
	}

	fieldsCounter ++;
	if (fieldsCounter == drawnNumber)
	{
		timerForPlayerMovementExecute->Enabled = false;
        this->fieldsVector[currentFieldNumber]->mainEventWhenPlayerIsOnTheField(player1_1);
		fieldsCounter = 0;
	}
}
//---------------------------------------------------------------------------


void __fastcall Tframe1Map::CornerButton1Click(TObject *Sender)
{
	Label1->Text = drawnNumber;
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
	timerForPlayerMovementExecute->Enabled = true;
}
//---------------------------------------------------------------------------


