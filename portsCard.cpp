//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "portsCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
//TportsCardFrame *portsCardFrame;
//---------------------------------------------------------------------------
__fastcall TportsCardFrame::TportsCardFrame(TComponent* Owner, int cardNumber)
	: TFrame(Owner)
{
	UnicodeString newName = this->Name;
	newName = newName.operator +=(UnicodeString(cardNumber));
	this->Name = newName;
    this->Parent = static_cast<TFrame*>(Owner);
	this->Visible = false;
	this->Position->X = 750;
	this->Position->Y = 220;
}
//---------------------------------------------------------------------------
void __fastcall TportsCardFrame::payButtonClick(TObject *Sender)
{

	Visible = false;
}
//---------------------------------------------------------------------------
