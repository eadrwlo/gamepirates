//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "startgameMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "playerMenu"
#pragma resource "*.fmx"
TstartgameSettingsMenu_frame *startgameSettingsMenu_frame;
//---------------------------------------------------------------------------
__fastcall TstartgameSettingsMenu_frame::TstartgameSettingsMenu_frame(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------