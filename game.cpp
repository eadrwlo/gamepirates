//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "game.h"
#include "Mainmenu.h"
#include "Optionsmenu.h"
#include "Ingamemenu.h"
#include "whirlpoolCard.h"
#include "startgameMenu.h"
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
	mainMenu_frame = new TmainMenu_frame(this);
	optionsMenu_frame = new ToptionsMenu_frame(this);
	frame1Map = new Tframe1Map(this);
	ingameMenu_frame = new TingameMenu_frame(this);
	startgameMenu_frame = new TstartgameMenu_frame(this);
	//whirlpoolCardFrame = new TwhirlpoolCardFrame(this);
}
//---------------------------------------------------------------------------
void TgameForm::mainMenuMusic()
{
	musicPlayer->Parent=this;
	musicPlayer->FileName = "../../sounds/mainmenu_music.mp3";
	musicPlayer->Play();
    //musicPlayer->Volume = ((optionsMenu_frame->volumeButton_button->Position->X -
						   //	optionsMenu_frame->volumeButton_button->Position->X)/180);
}

void TgameForm::startgameMenu()
{
	startgameMenu_frame->Visible = false;
	startgameMenu_frame->Parent = this;
}


void TgameForm::mainMenu()
{
	mainMenuBackground->Parent = this;
	mainMenuBackground->Height=1080;
	mainMenuBackground->Width=1920;
	mainMenuBackground->Bitmap->LoadFromFile("../../img/background/background.bmp");
	mainMenuBackground->Visible = true;
	mainMenuBackground->Align = 11;
	mainMenu_frame->Parent=this;
	mainMenu_frame->Height = 400;
	mainMenu_frame->Width = 300;
	mainMenu_frame->Visible = true;
}
//---------------------------------------------------------------------------
void TgameForm::optionsMenu()
{
    mainMenuMusic();
	optionsMenu_frame->Parent=this;
	optionsMenu_frame->Height = 400;
	optionsMenu_frame->Width = 300;
	optionsMenu_frame->Visible = false;
	if (gameForm->BorderStyle == 2 && gameForm->WindowState == 0)
	{
		optionsMenu_frame->checkON_gameInWindow->Visible = true;
		optionsMenu_frame->checkOFF_gameInWindow->Visible = false;
	}
	if (gameForm->BorderStyle == 0 && gameForm->WindowState == 2)
	{
		optionsMenu_frame->checkON_gameInWindow->Visible = false;
		optionsMenu_frame->checkOFF_gameInWindow->Visible = true;
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
	ingameMenu_frame->Height = 400;
	ingameMenu_frame->Width = 300;
	ingameMenu_frame->Visible = false;
	ingameMenu_frame->Parent = this;
}
//---------------------------------------------------------------------------
void __fastcall TgameForm::FormCreate(TObject *Sender)
{
	formSettings();
	mainMenu();
	startgameMenu();
	game();
	inGameMenu();
	optionsMenu();

}
//---------------------------------------------------------------------------
void __fastcall TgameForm::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (Key==VK_ESCAPE && frame1Map->Visible==true && ingameMenu_frame->Visible == false
	&& optionsMenu_frame->Visible == false)
	{
		ingameMenu_frame->Visible = true;
		inGameMenuBackground->Visible = true;
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==true && ingameMenu_frame->Visible == true)
	{
		ingameMenu_frame->Visible = false;
		inGameMenuBackground->Visible = false;
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==true && ingameMenu_frame->Visible == false
	&& optionsMenu_frame->Visible == true)
	{
		inGameMenuBackground->Visible = true;
		optionsMenu_frame->goBack_buttonClick(this);
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==false && ingameMenu_frame->Visible == false
	&& optionsMenu_frame->Visible == true)
	{
		inGameMenuBackground->Visible = false;
		optionsMenu_frame->goBack_buttonClick(this);
	}
}
//---------------------------------------------------------------------------

