//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "whirlpoolCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TwhirlpoolCardFrame *whirlpoolCardFrame;
//---------------------------------------------------------------------------
__fastcall TwhirlpoolCardFrame::TwhirlpoolCardFrame(TComponent* Owner)
	: TFrame(Owner)
{
	this->Parent = static_cast<TFrame*>(Owner);
	this->Visible = false;
	this->Position->X = 800;
	this->Position->Y = 280;
}

TGlyph *TwhirlpoolCardFrame::getNumber1()
{
    return number1;
}
//---------------------------------------------------------------------------


