//---------------------------------------------------------------------------

#ifndef pirateShipCardH
#define pirateShipCardH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TpirateShipCardFrame : public TFrame
{
__published:	// IDE-managed Components
	TImage *badPirate;
	TImage *closeButton;
	TImage *goodPirate;
	TLabel *amountOfBonusLabel;
	void __fastcall closeButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TpirateShipCardFrame(TComponent* Owner, int cardNumber);
};
//---------------------------------------------------------------------------
//extern PACKAGE TpirateShipCardFrame *pirateShipCardFrame;
//---------------------------------------------------------------------------
#endif
