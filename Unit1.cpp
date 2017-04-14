//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "Unit1.h"
#include "Mainmenu.h"
#include "Optionsmenu.h"
#include "Ingamemenu.h"
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frameMap"
#pragma resource "*.fmx"
TForm1 *Form1;
TImage *inGameMenuBackground;
TMediaPlayer *musicPlayer;
TImage *mainMenuBackground;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
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
void TForm1::mainMenuMusic()
{
	musicPlayer->Parent=this;
	musicPlayer->FileName = "../../sounds/mainmenu_music.mp3";
	musicPlayer->Play();
	musicPlayer->Volume = 0.5;
}


void TForm1::mainMenu()
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
void TForm1::optionsMenu()
{
	Options_frame->Parent=this;
	Options_frame->Height = 400;
	Options_frame->Width = 300;
	Options_frame->Visible = false;
	Options_frame->Parent = this;
	if (Form1->BorderStyle == 2 && Form1->WindowState == 0)
	{
		Options_frame->checkon_gra_w_oknie->Visible = true;
		Options_frame->checkoff_gra_w_oknie->Visible = false;
	}
	if (Form1->BorderStyle == 0 && Form1->WindowState == 2)
	{
		Options_frame->checkon_gra_w_oknie->Visible = false;
		Options_frame->checkoff_gra_w_oknie->Visible = true;
	}
}
//---------------------------------------------------------------------------
void TForm1::game()
{
	frame1Map->Parent = this;
	frame1Map->Visible = false;
    frame1Map->Align = 11;
}
//---------------------------------------------------------------------------
void TForm1::formSettings()
{
	Form1->Height=1080;
	Form1->Width=1920;
	//Form1->BorderStyle = 2;
	//Form1->WindowState = 0;
}
//---------------------------------------------------------------------------
void TForm1::inGameMenu()
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	formSettings();
	mainMenu();
	game();
	inGameMenu();
	optionsMenu();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
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
		Options_frame->wrocClick(Ingamemenu_frame);
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==false && Ingamemenu_frame->Visible == false
	&& Options_frame->Visible == true)
	{
		inGameMenuBackground->Visible = false;
		Options_frame->wrocClick(Mainmenu_frame);
	}
}
//---------------------------------------------------------------------------

