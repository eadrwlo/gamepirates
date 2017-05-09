//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "greatBritainCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TgreatBritainFrame *greatBritainFrame;
//---------------------------------------------------------------------------
__fastcall TgreatBritainFrame::TgreatBritainFrame(TComponent* Owner)
	: TFrame(Owner)
{
    this->Parent = static_cast<TFrame*>(Owner);
	this->Visible = false;
	this->Position->X = 750;
	this->Position->Y = 220;
}
//---------------------------------------------------------------------------
void __fastcall TgreatBritainFrame::buyButtonClick(TObject *Sender)
{

	Visible = false;
}
//---------------------------------------------------------------------------
