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
ToptionsMenu_frame *optionsMenu_frame;
POINT p;
int mouseXposiotion = 0;
bool isMouseDown = 0;

//---------------------------------------------------------------------------
__fastcall ToptionsMenu_frame::ToptionsMenu_frame(TComponent* Owner)
	: TFrame(Owner)
{
	volumeButton_button->Position->X = volumeBar_label->Position->X + 0.5*(volumeBar_label->Width);
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
void __fastcall ToptionsMenu_frame::goBack_buttonClick(TObject *Sender)
{
	if(frame1Map->Visible == true)
	{
		ingameMenu_frame->Visible=true;
		optionsMenu_frame->Visible=false;
	}
	else
	{
		mainMenu_frame->Visible=true;
		optionsMenu_frame->Visible=false;
    }

}
//---------------------------------------------------------------------------
void __fastcall ToptionsMenu_frame::checkON_gameInWindowClick(TObject *Sender)
{
	 checkON_gameInWindow->Visible = false;
	 checkOFF_gameInWindow->Visible = true;
	 gameForm->BorderStyle = 0;
	 gameForm->WindowState = 2;
}
//---------------------------------------------------------------------------
void __fastcall ToptionsMenu_frame::checkOFF_gameInWindowClick(TObject *Sender)
{
	checkON_gameInWindow->Visible = true;
	checkOFF_gameInWindow->Visible = false;
	gameForm->BorderStyle = 2;
	gameForm->WindowState = 0;
}
//---------------------------------------------------------------------------
void __fastcall ToptionsMenu_frame::checkOFF_musicClick(TObject *Sender)
{
	checkOFF_music->Visible = false;
	checkON_music->Visible = true;
    musicPlayer->Play();
}
//---------------------------------------------------------------------------

void __fastcall ToptionsMenu_frame::checkON_musicClick(TObject *Sender)
{
    musicPlayer->Stop();
	checkOFF_music->Visible = true;
	checkON_music->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall ToptionsMenu_frame::volumeButton_buttonMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	GetCursorPos(&p);
	mouseXposiotion = p.x;
	isMouseDown = true;
	volumeButton_timer->Enabled = true;
	if (volumeButton_button->Position->X <= volumeBar_label->Position->X)
		{
			volumeButton_timer->Enabled = true;
		}
}
//---------------------------------------------------------------------------

void __fastcall ToptionsMenu_frame::volumeButton_timerTimer(TObject *Sender)
{
    POINT p;
	GetCursorPos(&p);
	int currentPosition = 0;
	if (isMouseDown == true)
	{
		currentPosition = volumeButton_button->Position->X + (p.x - mouseXposiotion);
		volumeButton_button->Position->X =  currentPosition;
		mouseXposiotion = p.x;
		musicPlayer->Volume = ((volumeButton_button->Position->X - volumeBar_label->Position->X)/180);
		if (volumeButton_button->Position->X <= volumeBar_label->Position->X - 3)
		{
			volumeButton_button->Position->X = volumeBar_label->Position->X-2;
			isMouseDown == false;
			volumeButton_timer->Enabled = false;
		}
		if (volumeButton_button->Position->X >= (volumeBar_label->Position->X + volumeBar_label->Width - 3))
		{
			volumeButton_button->Position->X = volumeBar_label->Position->X + volumeBar_label->Width -4;
			isMouseDown == false;
			volumeButton_timer->Enabled = false;
		}

	}
}
//---------------------------------------------------------------------------


void __fastcall ToptionsMenu_frame::volumeButton_buttonMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
    isMouseDown = false;
}
//---------------------------------------------------------------------------


