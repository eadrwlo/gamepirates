//---------------------------------------------------------------------------

#ifndef conquerPortMiniGameH
#define conquerPortMiniGameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <vector>
#include "player.h"
#include "portsCard.h"
class Player;
class TportsCardFrame;

//---------------------------------------------------------------------------
class TconquerPortMiniGameForm : public TForm
{
__published:	// IDE-managed Components
	TImage *shipLeft;
	TImage *shipRight;
	TImage *leftBall;
	TTimer *rightBallTimer;
	TImage *rightBall;
	TTimer *leftBallTimer;
	TImage *background;
	TImage *leftGamerBottle1;
	TImage *bar;
	TImage *leftGamerBottle2;
	TImage *leftGamerBottle3;
	TImage *rightGamerBottle3;
	TImage *rightGamerBottle2;
	TImage *rightGamerBottle1;
	TLabel *leftPlayerName;
	TLabel *rightPlayerName;
	TImage *winLabelImage;
	TLabel *winnerName;
	TImage *closeButtonImage;
	TImage *winnerInfoBackground;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall rightBallTimerTimer(TObject *Sender);
	void __fastcall leftBallTimerTimer(TObject *Sender);
	void __fastcall closeButtonImageClick(TObject *Sender);
private:	// User declarations
	float oldLeftBallY;
	float oldLeftBallX;
	float oldRightBallY;
	float oldRightBallX;
	Player *DefendingPlayer;
	Player *AttackingPlayer;
	std::vector <TImage*> bottlesRight;
	std::vector <TImage*> bottlesLeft;
	TportsCardFrame *cardOfRelatedPort;
public:		// User declarations
	__fastcall TconquerPortMiniGameForm(TComponent* Owner);
	void runConquerPortMiniGame(Player *DefendingPlayer, Player *AttackingPlayer, TportsCardFrame *cardOfRelatedPort);
    void handleEndOfTheMiniGame();
};
//---------------------------------------------------------------------------
extern PACKAGE TconquerPortMiniGameForm *conquerPortMiniGameForm;
//---------------------------------------------------------------------------
#endif
