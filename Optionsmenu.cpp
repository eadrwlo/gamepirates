//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "Optionsmenu.h"
#include "Unit1.h"
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
}
//---------------------------------------------------------------------------
void __fastcall TOptions_frame::wrocClick(TObject *Sender)
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
void __fastcall TOptions_frame::checkon_gra_w_oknieClick(TObject *Sender)
{
	 checkon_gra_w_oknie->Visible = false;
	 checkoff_gra_w_oknie->Visible = true;
	 Form1->BorderStyle = 0;
	 Form1->WindowState = 2;
}
//---------------------------------------------------------------------------
void __fastcall TOptions_frame::checkoff_gra_w_oknieClick(TObject *Sender)
{
	checkon_gra_w_oknie->Visible = true;
	checkoff_gra_w_oknie->Visible = false;
	Form1->BorderStyle = 2;
	Form1->WindowState = 0;
}
//---------------------------------------------------------------------------
