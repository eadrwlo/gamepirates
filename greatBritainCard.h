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
#include "Player.h"
//---------------------------------------------------------------------------
class TgreatBritainFrame : public TFrame
{
    friend class Port;
__published:	// IDE-managed Components
	TImage *cardImage;
	TColorButton *payButton;
	TColorButton *conquerButton;
	TLabel *extensionLvlLabel;
	TLabel *ownerLabel;
	TLabel *conquerCostLabel;
	TLabel *visitingPaymentLabel;
	void __fastcall payButtonClick(TObject *Sender);

private:	// User declarations
	Player *currentlyOperatedPlayer;
	Port *portRelatedWithCard;
public:		// User declarations
	__fastcall TgreatBritainFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TgreatBritainFrame *greatBritainFrame;
//---------------------------------------------------------------------------
#endif
