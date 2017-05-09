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
#include "gameLib.h"
#include <FMX.Colors.hpp>
#include <FMX.Styles.Objects.hpp>
#include <FMX.Effects.hpp>
#include <FMX.Filter.Effects.hpp>
#include <vector>
//---------------------------------------------------------------------------
class Tframe1Map : public TFrame
{
__published:	// IDE-managed Components
	TImage *field06;
	TImage *field10;
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
	TTimer *timerForDice;
	TImageList *diceWalls;
	TGlyph *dice;
	TTimer *timerForThrowImagePulsing;
	TImage *player1;
	TFloatAnimation *moveInXAxis;
	TFloatAnimation *moveInYAxis;
	TImage *background;
	TTimer *groundMovement;
	TTimer *timerForPlayerMovement;
	TTimer *timerForPlayerMovementExecute;
	TCornerButton *CornerButton1;
	TColorAnimation *ColorAnimation1;
	TCornerButton *CornerButton2;
	TImage *player3;
	TFloatAnimation *FloatAnimation3;
	TFloatAnimation *FloatAnimation4;
	TImage *portGrbrtain4;
	TImage *portGrbrtain3;
	TImage *portGrbrtain2;
	TImage *portGrbrtain;
	TImage *Image4;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	TImage *Image9;
	TImage *Image10;
	TImage *Image11;
	TImage *Image12;
	TImage *Image13;
	TImage *Image14;
	TImage *Image15;
	TImage *Image16;
	void __fastcall startStopThrowingClick(TObject *Sender);
	void __fastcall timerForDiceTimer(TObject *Sender);
	void __fastcall przesunClick(TObject *Sender);
	void __fastcall groundMovementTimer(TObject *Sender);
	void __fastcall timerForPlayerMovementExecuteTimer(TObject *Sender);
	void __fastcall CornerButton1Click(TObject *Sender);
	void __fastcall CornerButton2Click(TObject *Sender);
private:	// User declarations
	vector<Field*> fieldsVector;
	int fieldsCounter;
	int drawnNumber;
public:		// User declarations
	__fastcall Tframe1Map(TComponent* Owner);
	//friend void throwDice();
    void fillFieldsVectorWithFields();
};
//---------------------------------------------------------------------------
extern PACKAGE Tframe1Map *frame1Map;
//---------------------------------------------------------------------------
#endif
