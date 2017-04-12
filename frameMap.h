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
	TImage *field06;
	TImage *Image36;
	TImage *field09;
	TImage *field08;
	TImage *field07;
	TImage *field05;
	TImage *field04;
	TImage *field03;
	TImage *field02;
	TImage *field01;
	TImage *field36;
	TImage *field35;
	TImage *field34;
	TImage *field33;
	TImage *field32;
	TImage *field31;
	TImage *field30;
	TImage *field29;
	TImage *field11;
	TImage *field12;
	TImage *field13;
	TImage *field14;
	TImage *field15;
	TImage *field16;
	TImage *field17;
	TImage *field18;
	TImage *field19;
	TImage *field20;
	TImage *field21;
	TImage *field22;
	TImage *field23;
	TImage *field24;
	TImage *field25;
	TImage *field26;
	TImage *field27;
	TImage *field28;
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
	TImage *field10;
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
