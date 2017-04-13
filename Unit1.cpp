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

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm1::mainMenuMusic()
{
    TMediaPlayer *MusicPlayer = new TMediaPlayer(this);
	MusicPlayer->Parent=this;
	MusicPlayer->FileName = "../../sounds/mainmenu_music.mp3";
	MusicPlayer->Play();
	MusicPlayer->Tag = 2;
	MusicPlayer->Volume = 0.5;
}


void TForm1::MainMenu()
{
    mainMenuMusic();
	TImage *MainMenuBackground = new TImage(this);
	MainMenuBackground->Parent = this;
	MainMenuBackground->Height=1080;
	MainMenuBackground->Width=1920;
	MainMenuBackground->Bitmap->LoadFromFile("../../img/background/background.bmp");
	MainMenuBackground->Visible = true;
	MainMenuBackground->Align = 11;

	Mainmenu_frame = new TMainmenu_frame(this);
	Mainmenu_frame->Parent=this;
	Mainmenu_frame->Height = 400;
	Mainmenu_frame->Width = 300;
	Mainmenu_frame->Visible = true;
	Mainmenu_frame->Parent = this;
}
//---------------------------------------------------------------------------
void TForm1::OptionsMenu()
{
	Options_frame = new TOptions_frame(this);
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
void TForm1::Game()
{
	frame1Map = new Tframe1Map(this);
	frame1Map->Parent = this;
	frame1Map->Visible = false;
    frame1Map->Align = 11;
}
//---------------------------------------------------------------------------
void TForm1::FormSettings()
{
	Form1->Height=1080;
	Form1->Width=1920;
	Form1->BorderStyle == 2;
	Form1->WindowState == 0;
}
//---------------------------------------------------------------------------
void TForm1::InGameMenu()
{
	Ingamemenu_frame = new TIngamemenu_frame(this);
	Ingamemenu_frame->Parent=this;
	Ingamemenu_frame->Height = 400;
	Ingamemenu_frame->Width = 300;
	Ingamemenu_frame->Visible = false;
	Ingamemenu_frame->Parent = this;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	FormSettings();
	MainMenu();
	Game();
	OptionsMenu();
	InGameMenu();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (Key==VK_ESCAPE && frame1Map->Visible==true && Ingamemenu_frame->Visible == false
	&& Options_frame->Visible == false)
	{
		Ingamemenu_frame->Visible = true;
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==true && Ingamemenu_frame->Visible == true)
	{
		Ingamemenu_frame->Visible = false;
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==true && Ingamemenu_frame->Visible == false
	&& Options_frame->Visible == true)
	{
		Options_frame->wrocClick(Ingamemenu_frame);
	}
	else if (Key==VK_ESCAPE && frame1Map->Visible==false && Ingamemenu_frame->Visible == false
	&& Options_frame->Visible == true)
	{
		Options_frame->wrocClick(Mainmenu_frame);
	}
}
//---------------------------------------------------------------------------

