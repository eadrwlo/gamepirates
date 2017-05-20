//---------------------------------------------------------------------------

#ifndef portsCardH
#define portsCardH
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
#include <FMX.Ani.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
class Player;
//---------------------------------------------------------------------------
class TportsCardFrame : public TFrame
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
	TImageList *writingsForEachCountryImageList;
	TGlyph *writing;
	TImageList *flagsImageList;
	TGlyph *flagImage;
	TLabel *cityLabel;
	void __fastcall payButtonClick(TObject *Sender);

private:	// User declarations
	Player *currentlyOperatedPlayer;
	Port *portRelatedWithCard;
public:		// User declarations
	__fastcall TportsCardFrame(TComponent* Owner, int cardNumber);
};
//---------------------------------------------------------------------------
//extern PACKAGE TportsCardFrame *portsCardFrame;
//---------------------------------------------------------------------------
#endif
