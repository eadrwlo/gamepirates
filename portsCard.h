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
	TLabel *extensionLvlLabel;
	TLabel *ownerLabel;
	TLabel *conquerCostLabel;
	TLabel *visitingPaymentLabel;
	TImageList *writingsForEachCountryImageList;
	TGlyph *writing;
	TImageList *flagsImageList;
	TGlyph *flagImage;
	TLabel *cityLabel;
	TImage *payButton;
	TImage *conquerButton;
	TImage *closeButton;
	TImage *buildButton;
	void __fastcall conquerButtonClick(TObject *Sender);
	void __fastcall payButtonClick(TObject *Sender);
	void __fastcall closeButtonClick(TObject *Sender);
	void __fastcall buildButtonClick(TObject *Sender);

private:	// User declarations
	//Player *currentlyOperatedPlayer;
	//Player *ownerOfRelatedPort;
	Port *portRelatedWithCard;
public:		// User declarations
	__fastcall TportsCardFrame(TComponent* Owner, int cardNumber);
	//Player* getOwnerOfRelatedPort();
	void setCurrentlyOperatedPlayer(Player *player);
    void shoutDownCard();

};
//---------------------------------------------------------------------------
//extern PACKAGE TportsCardFrame *portsCardFrame;
//---------------------------------------------------------------------------
#endif
