//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "mainMenu.h"
#include "Optionsmenu.h"
//#include "frameMap.h"
#include "startgameMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TmainMenu_frame *mainMenu_frame;
//---------------------------------------------------------------------------
__fastcall TmainMenu_frame::TmainMenu_frame(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TmainMenu_frame::endgame_buttonClick(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TmainMenu_frame::options_buttonClick(TObject *Sender)
{
	mainMenu_frame->Visible = false;
	optionsMenu_frame->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TmainMenu_frame::startgame_buttonClick(TObject *Sender)
{
	//frame1Map->Visible = Visible;
    mainMenu_frame->Visible = false;
	startgameMenu_frame->Visible = true;
}
//---------------------------------------------------------------------------


