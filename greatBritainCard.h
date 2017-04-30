//---------------------------------------------------------------------------

#ifndef greatBritainCardH
#define greatBritainCardH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TgreatBritainFrame : public TFrame
{
__published:	// IDE-managed Components
	TImage *Image1;
	TColorButton *buyButton;
	TColorButton *ColorButton1;
	void __fastcall buyButtonClick(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, float X, float Y);

private:	// User declarations
public:		// User declarations
	__fastcall TgreatBritainFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TgreatBritainFrame *greatBritainFrame;
//---------------------------------------------------------------------------
#endif
