//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "ingameMenu.h"
#include "optionsMenu.h"
#include "frameMap.h"
#include "game.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TingameMenu_frame *ingameMenu_frame;
//---------------------------------------------------------------------------

__fastcall TingameMenu_frame::TingameMenu_frame(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TingameMenu_frame::options_buttonClick(TObject *Sender)
{
	ingameMenu_frame->Visible = false;
	optionsMenu_frame->Visible = true;
    inGameMenuBackground->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TingameMenu_frame::endgame_buttonClick(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TingameMenu_frame::goBackToGame_buttonClick(TObject *Sender)
{
	ingameMenu_frame->Visible = false;
    inGameMenuBackground->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TingameMenu_frame::goToMainMenu_buttonClick(TObject *Sender)
{
	mainMenu_frame->Visible = true;
	ingameMenu_frame->Visible = false;
	frame1Map->Visible = false;
    inGameMenuBackground->Visible = false;
}
//---------------------------------------------------------------------------



