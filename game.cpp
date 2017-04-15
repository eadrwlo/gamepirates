//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "game.h"
#include "Mainmenu.h"
#include "Optionsmenu.h"
#include "Ingamemenu.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frameMap"
#pragma resource "*.fmx"
TgameForm *gameForm;
TImage *inGameMenuBackground;
TMediaPlayer *musicPlayer;
TImage *mainMenuBackground;

//---------------------------------------------------------------------------
__fastcall TgameForm::TgameForm(TComponent* Owner)
	: TForm(Owner)
{
	inGameMenuBackground = new TImage(this);
	musicPlayer = new TMediaPlayer(this);
	mainMenuBackground = new TImage(this);
	Mainmenu_frame = new TMainmenu_frame(this);
	Options_frame = new TOptions_frame(this);
	frame1Map = new Tframe1Map(this);
	Ingamemenu_frame = new TIngamemenu_frame(this);
}
//---------------------------------------------------------------------------
void TgameForm::mainMenuMusic()
{
	musicPlayer->Parent=this;
	musicPlayer->FileName = "../../sounds/mainmenu_music.mp3";
	musicPlayer->Play();
	musicPlayer->Volume = 0.5;
}


void TgameForm::mainMenu()
{
	mainMenuMusic();
	mainMenuBackground->Parent = this;
	mainMenuBackground->Height=1080;
	mainMenuBackground->Width=1920;
	mainMenuBackground->Bitmap->LoadFromFile("../../img/background/background.bmp");
	mainMenuBackground->Visible = true;
	mainMenuBackground->Align = 11;
	Mainmenu_frame->Parent=this;
	Mainmenu_frame->Height = 400;
	Mainmenu_frame->Width = 300;
	Mainmenu_frame->Visible = true;
	Mainmenu_frame->Parent = this;
}
//---------------------------------------------------------------------------
void TgameForm::optionsMenu()
{
	Options_frame->Parent=this;
	Options_frame->Height = 400;
	Options_frame->Width = 300;
	Options_frame->Visible = false;
	Options_frame->Parent = this;
	if (gameForm->BorderStyle == 2 && gameForm->WindowState == 0)
	{
		Options_frame->checkON_gameInWindow->Visible = true;
		Options_frame->checkOFF_gameInWindow->Visible = false;
	}
	if (gameForm->BorderStyle == 0 && gameForm->WindowState == 2)
	{
		Options_frame->checkON_gameInWindow->Visible = false;
		Options_frame->checkOFF_gameInWindow->Visible = true;
	}
}
//---------------------------------------------------------------------------
void TgameForm::game()
{
	frame1Map->Parent = this;
	frame1Map->Visible = false;
    frame1Map->Align = 11;
}
//---------------------------------------------------------------------------
void TgameForm::formSettings()
{
	gameForm->Height=1080;
	gameForm->Width=1920;
	//Form1->BorderStyle = 2;
	//Form1->WindowState = 0;
}
//---------------------------------------------------------------------------
void TgameForm::inGameMenu()
{
	inGameMenuBackground->Parent = this;
	inGameMenuBackground->Height=1080;
	inGameMenuBackground->Width=1920;
	inGameMenuBackground->Bitmap->LoadFromFile("../../img/ingame_menu/ingamemenu_background.bmp");
	inGameMenuBackground->Visible = false;
	inGameMenuBackground->Align = 11;
	inGameMenuBackground->Opacity = 0.7;
	Ingamemenu_frame->Parent=this;
	Ingamemenu_frame->Height = 400;
	Ingamemenu_frame->Width = 300;
	Ingamemenu_frame->Visible = false;
	Ingamemenu_frame->Parent = this;
}
//---------------------------------------------------------------------------
void __fastcall TgameForm::FormCreate(TObject *Sender)
{
	formSettings();
	mainMenu();
	game();
	inGameMenu();
	optionsMenu();

}
//---------------------------------------------------------------------------
void __fastcall TgameForm::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (Key==VK_ESCAPE && frame1Map->Visible==true && Ingamemenu_frame->Visible == false
	&& Options_frame->Visible == false)
	{
		Ingamemenu_frame->Visible = true;
		inGameMenuBackground->Visible = true;
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==true && Ingamemenu_frame->Visible == true)
	{
		Ingamemenu_frame->Visible = false;
		inGameMenuBackground->Visible = false;
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==true && Ingamemenu_frame->Visible == false
	&& Options_frame->Visible == true)
	{
		inGameMenuBackground->Visible = true;
		Options_frame->goBack_buttonClick(this);
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==false && Ingamemenu_frame->Visible == false
	&& Options_frame->Visible == true)
	{
		inGameMenuBackground->Visible = false;
		Options_frame->goBack_buttonClick(this);
	}
}
//---------------------------------------------------------------------------

