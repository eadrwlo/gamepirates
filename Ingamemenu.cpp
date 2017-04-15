//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "inGameMenu.h"
#include "optionsmenu.h"
#include "frameMap.h"
#include "game.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TIngamemenu_frame *Ingamemenu_frame;
//---------------------------------------------------------------------------

__fastcall TIngamemenu_frame::TIngamemenu_frame(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TIngamemenu_frame::options_buttonClick(TObject *Sender)
{
	Ingamemenu_frame->Visible = false;
	Options_frame->Visible = true;
    inGameMenuBackground->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TIngamemenu_frame::endgame_buttonClick(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TIngamemenu_frame::goBackToGame_buttonClick(TObject *Sender)
{
	Ingamemenu_frame->Visible = false;
    inGameMenuBackground->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TIngamemenu_frame::goToMainMenu_buttonClick(TObject *Sender)
{
	Mainmenu_frame->Visible = true;
	Ingamemenu_frame->Visible = false;
	frame1Map->Visible = false;
    inGameMenuBackground->Visible = false;

}
//---------------------------------------------------------------------------



