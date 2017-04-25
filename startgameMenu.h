//---------------------------------------------------------------------------

#ifndef startgameMenuH
#define startgameMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "playerMenu.h"
//---------------------------------------------------------------------------
class TstartgameSettingsMenu_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TLabel *numberOfPlayers_label;
	Tplayer_frame *Frame11;
	Tplayer_frame *Frame12;
private:	// User declarations
public:		// User declarations
	__fastcall TstartgameSettingsMenu_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TstartgameSettingsMenu_frame *startgameSettingsMenu_frame;
//---------------------------------------------------------------------------
#endif
