//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "Unit1.h"
#include "gameLib.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
Player *player;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{
    player->setName("Adrian");
}
//---------------------------------------------------------------------------

