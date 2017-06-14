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
class TpirateShipFrame : public TFrame
{
__published:	// IDE-managed Components
	TImage *badPirate;
	TImage *closeButton;
	TImage *goodPirate;
	TLabel *amountOfBonusLabel;
	void __fastcall closeButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TpirateShipFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TpirateShipFrame *pirateShipFrame;
//---------------------------------------------------------------------------
#endif
