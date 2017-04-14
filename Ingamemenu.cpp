//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Ingamemenu.h"
#include "Optionsmenu.h"
#include "frameMap.h"
#include "Unit1.h"
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
    inGameMenuBackground->Visible = true;
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
    inGameMenuBackground->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TIngamemenu_frame::Image2Click(TObject *Sender)
{
	Mainmenu_frame->Visible = true;
	Ingamemenu_frame->Visible = false;
	frame1Map->Visible = false;
    inGameMenuBackground->Visible = false;

}
//---------------------------------------------------------------------------

void inGameMenuBackgroundVisibility(bool val)
{
	//TImage *MainMenuBackground = new TImage(Form1);
	//MainMenuBackground->Parent = Form1;
	//MainMenuBackground->Height=1080;
	//MainMenuBackground->Width=1920;
   //	MainMenuBackground->Bitmap->LoadFromFile("../../img/ingame_menu/ingamemenu_background.bmp");
   //	MainMenuBackground->Visible = false;
  //	MainMenuBackground->Align = 11;
}



