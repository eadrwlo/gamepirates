//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Mainmenu.h"
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
void __fastcall TMainmenu_frame::Endgame_buttonClick(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TMainmenu_frame::Options_buttonClick(TObject *Sender)
{
	Mainmenu_frame->Visible = false;
	Options_frame->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TMainmenu_frame::Startgame_buttonClick(TObject *Sender)
{
    frame1Map->Visible = Visible;
}
//---------------------------------------------------------------------------

