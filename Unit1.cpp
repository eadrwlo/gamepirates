//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "Unit1.h"
#include "Mainmenu.h"
#include "gameLib.h"
#include "Optionsmenu.h"
#include "frameMap.h"
#include <iostream>
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frameMap"
#pragma resource "*.fmx"
TForm1 *Form1;
Player *player;
std::vector <TMainmenu_frame*> buttons;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{
	player->setName("Adrian");
}
//---------------------------------------------------------------------------
void TForm1::MainMenu()
{
	TImage *MainMenuBackground = new TImage(this);
		MainMenuBackground->Parent = this;
		MainMenuBackground->Height=1080;
		MainMenuBackground->Width=1920;
		MainMenuBackground->Bitmap->LoadFromFile("../../img/MainMenu/background.bmp");
		MainMenuBackground->Visible = true;

		Mainmenu_frame = new TMainmenu_frame(this);
		Mainmenu_frame->Parent=this;
		Mainmenu_frame->Height = 400;
		Mainmenu_frame->Width = 300;
		Mainmenu_frame->Visible = true;
		Mainmenu_frame->Parent = this;
}

void TForm1::OptionsMenu()
{
		Options_frame = new TOptions_frame(this);
		Options_frame->Parent=this;
		Options_frame->Height = 400;
		Options_frame->Width = 300;
		Options_frame->Visible = false;
		Options_frame->Parent = this;
}


void TForm1::Game()
{
	frame1Map = new Tframe1Map(this);
	frame1Map->Parent = this;
	frame1Map->Visible = false;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	MainMenu();
	OptionsMenu();
    Game();
}




