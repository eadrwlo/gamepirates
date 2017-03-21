//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Ingamemenu.h"
#include "Optionsmenu.h"
#include "frameMap.h"
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

void __fastcall TIngamemenu_frame::Options_buttonClick(TObject *Sender)
{
	Ingamemenu_frame->Visible = false;
	Options_frame->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TIngamemenu_frame::Endgame_buttonClick(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TIngamemenu_frame::Image1Click(TObject *Sender)
{
    Ingamemenu_frame->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TIngamemenu_frame::Image2Click(TObject *Sender)
{
	Mainmenu_frame->Visible = true;
	Ingamemenu_frame->Visible = false;
	frame1Map->Visible = false;

}
//---------------------------------------------------------------------------

