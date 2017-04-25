//---------------------------------------------------------------------------

#ifndef playerMenuH
#define playerMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class Tplayer_frame : public TFrame
{
__published:	// IDE-managed Components
	TText *Text1;
	TImage *Image1;
private:	// User declarations
public:		// User declarations
	__fastcall Tplayer_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tplayer_frame *player_frame;
//---------------------------------------------------------------------------
#endif
