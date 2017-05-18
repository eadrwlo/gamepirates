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
#include "Port.h"
//---------------------------------------------------------------------------
class TgreatBritainFrame : public TFrame
{
    friend class Port;
__published:	// IDE-managed Components
	TImage *cardImage;
	TColorButton *buyButton;
	TColorButton *conquerButton;
	void __fastcall buyButtonClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TgreatBritainFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TgreatBritainFrame *greatBritainFrame;
//---------------------------------------------------------------------------
#endif
