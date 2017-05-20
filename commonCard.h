//---------------------------------------------------------------------------

#ifndef commonCardH
#define commonCardH
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
//---------------------------------------------------------------------------
class TcommonCardFrame : public TFrame
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
	TColorAnimation *ColorAnimation1;
	void __fastcall payButtonClick(TObject *Sender);

private:	// User declarations
	Player *currentlyOperatedPlayer;
	Port *portRelatedWithCard;
public:		// User declarations
	__fastcall TcommonCardFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TcommonCardFrame *commonCardFrame;
//---------------------------------------------------------------------------
#endif
