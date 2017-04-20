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
POINT p;
int mouseXposiotion = 0;
int mouseYposiotion = 0;
bool isMouseDown = 0;

//---------------------------------------------------------------------------
__fastcall TOptions_frame::TOptions_frame(TComponent* Owner)
	: TFrame(Owner)
{

	musicPlayer->Volume = ((volumeButton_button->Position->X - volumeBar_label->Position->X)/180);
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


void __fastcall TOptions_frame::volumeButton_buttonMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	GetCursorPos(&p);
	mouseXposiotion = p.x;
	mouseYposiotion = p.y;
	isMouseDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TOptions_frame::volumeButton_timerTimer(TObject *Sender)
{
	if (mouseXposiotion != 0 && isMouseDown == true)
	{
		POINT p;
		GetCursorPos(&p);
		volumeButton_button->Position->X = volumeButton_button->Position->X + (p.x - mouseXposiotion);
		mouseXposiotion = p.x;
		musicPlayer->Volume = ((volumeButton_button->Position->X - volumeBar_label->Position->X)/180);
	}
}
//---------------------------------------------------------------------------


void __fastcall TOptions_frame::volumeButton_buttonMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
    isMouseDown = false;
}
//---------------------------------------------------------------------------

void __fastcall TOptions_frame::FrameMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
    isMouseDown = false;
}
//---------------------------------------------------------------------------

