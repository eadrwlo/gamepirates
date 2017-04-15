//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "mainMenu.h"
#include "Optionsmenu.h"
#include "frameMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMainmenu_frame *Mainmenu_frame;
//---------------------------------------------------------------------------
__fastcall TMainmenu_frame::TMainmenu_frame(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainmenu_frame::endgame_buttonClick(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TMainmenu_frame::options_buttonClick(TObject *Sender)
{
	Mainmenu_frame->Visible = false;
	Options_frame->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TMainmenu_frame::startgame_buttonClick(TObject *Sender)
{
    frame1Map->Visible = Visible;
}
//---------------------------------------------------------------------------

