//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <ctime>
#include "frameMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tframe1Map *frame1Map;
int number = 1;

//---------------------------------------------------------------------------
__fastcall Tframe1Map::Tframe1Map(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tframe1Map::startStopThrowingClick(TObject *Sender)
{
	AnsiString throwTheDice = "Throw the Dice !";
	AnsiString stopTheDice = "Stop the Dice !";
	Label1->Text = " ";
//	else if (Button1->Text == stopTheDice)
//	{
//		Button1->Text = throwTheDice;
//    }
	timerForDice->Enabled = !(timerForDice->Enabled);
}
//---------------------------------------------------------------------------

void __fastcall Tframe1Map::timerForDiceTimer(TObject *Sender)
{
		Label1->Text = number;
		dice->ImageIndex = number - 1;
		number ++;
		if (number == 7)
			number = 1;
}
//---------------------------------------------------------------------------


