//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "optionsMenu.h"
#include "game.h"
#include "frameMap.h"
#include "Ingamemenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TOptions_frame *Options_frame;
//---------------------------------------------------------------------------
__fastcall TOptions_frame::TOptions_frame(TComponent* Owner)
	: TFrame(Owner)
{
    if (musicPlayer->State == 0)
	{
		checkOFF_music->Visible = false;
		checkON_music->Visible = true;
	}
	else
	{
		checkOFF_music->Visible = true;
		checkON_music->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TOptions_frame::goBack_buttonClick(TObject *Sender)
{
	if(frame1Map->Visible == true)
	{
		Ingamemenu_frame->Visible=true;
		Options_frame->Visible=false;
	}
	else
	{
		Mainmenu_frame->Visible=true;
		Options_frame->Visible=false;
    }

}
//---------------------------------------------------------------------------
void __fastcall TOptions_frame::checkON_gameInWindowClick(TObject *Sender)
{
	 checkON_gameInWindow->Visible = false;
	 checkOFF_gameInWindow->Visible = true;
	 gameForm->BorderStyle = 0;
	 gameForm->WindowState = 2;
}
//---------------------------------------------------------------------------
void __fastcall TOptions_frame::checkOFF_gameInWindowClick(TObject *Sender)
{
	checkON_gameInWindow->Visible = true;
	checkOFF_gameInWindow->Visible = false;
	gameForm->BorderStyle = 2;
	gameForm->WindowState = 0;
}
//---------------------------------------------------------------------------
void __fastcall TOptions_frame::checkOFF_musicClick(TObject *Sender)
{
	checkOFF_music->Visible = false;
	checkON_music->Visible = true;
    musicPlayer->Play();
}
//---------------------------------------------------------------------------

void __fastcall TOptions_frame::checkON_musicClick(TObject *Sender)
{
    musicPlayer->Stop();
	checkOFF_music->Visible = true;
	checkON_music->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TOptions_frame::volumeButton_buttonClick(TObject *Sender)
{
	//volumeButton->Parent = volumeBar;
	volumeButton_button->DragMode = 2;
}
//---------------------------------------------------------------------------



