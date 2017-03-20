//---------------------------------------------------------------------------

#ifndef IngamemenuH
#define IngamemenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TIngamemenu_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *Options_button;
	TImage *Endgame_button;
	TImage *Image1;
	TImage *Image2;
private:	// User declarations
public:		// User declarations
	__fastcall TIngamemenu_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIngamemenu_frame *Ingamemenu_frame;
//---------------------------------------------------------------------------
#endif
