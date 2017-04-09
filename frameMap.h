//---------------------------------------------------------------------------

#ifndef frameMapH
#define frameMapH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include <FMX.Ani.hpp>
//---------------------------------------------------------------------------
class Tframe1Map : public TFrame
{
__published:	// IDE-managed Components
	TImage *Image33;
	TImage *Image36;
	TImage *Image19;
	TImage *Image35;
	TImage *Image34;
	TImage *Image32;
	TImage *Image31;
	TImage *Image30;
	TImage *Image29;
	TImage *Image28;
	TImage *Image27;
	TImage *Image26;
	TImage *Image25;
	TImage *Image24;
	TImage *Image23;
	TImage *Image22;
	TImage *Image21;
	TImage *Image20;
	TImage *Image18;
	TImage *Image17;
	TImage *Image16;
	TImage *Image15;
	TImage *Image14;
	TImage *Image13;
	TImage *Image12;
	TImage *Image11;
	TImage *Image10;
	TImage *Image9;
	TImage *Image8;
	TImage *Image7;
	TImage *Image6;
	TImage *Image5;
	TImage *Image4;
	TImage *Image3;
	TImage *Image2;
	TImage *Image1;
	TLabel *Label1;
	TButton *startStopThrowing;
	TTimer *timerForDice;
	TImageList *diceWalls;
	TGlyph *dice;
	TImage *startStopThrowing2;
	TTimer *timerForThrowImagePulsing;
	TImage *player1;
	TButton *przesun;
	TFloatAnimation *moveInXAxis;
	TFloatAnimation *moveInYAxis;
	TImage *Image38;
	TFloatAnimation *FloatAnimation1;
	TFloatAnimation *FloatAnimation2;
	TImage *Image37;
	TImage *background;
	TTimer *Timer1;
	void __fastcall startStopThrowingClick(TObject *Sender);
	void __fastcall timerForDiceTimer(TObject *Sender);
	void __fastcall przesunClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tframe1Map(TComponent* Owner);
    friend void throwDice();
};
//---------------------------------------------------------------------------
extern PACKAGE Tframe1Map *frame1Map;
//---------------------------------------------------------------------------
#endif
