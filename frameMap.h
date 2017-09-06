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
#include "Port.h"
#include <FMX.Colors.hpp>
#include <FMX.Styles.Objects.hpp>
#include <FMX.Effects.hpp>
#include <FMX.Filter.Effects.hpp>
#include "playerStatisticsBox.h"
//---------------------------------------------------------------------------
class Tframe1Map : public TFrame
{
__published:	// IDE-managed Components
	TImage *field05;
	TImage *field09;
	TImage *field08;
	TImage *field07;
	TImage *field06;
	TImage *field04;
	TImage *field03;
	TImage *field02;
	TImage *field01;
	TImage *field00;
	TImage *field35;
	TImage *field34;
	TImage *field33;
	TImage *field32;
	TImage *field31;
	TImage *field30;
	TImage *field29;
	TImage *field28;
	TImage *field10;
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
	TLabel *Label1;
	TTimer *timerForDice;
	TImageList *diceWalls;
	TGlyph *dice;
	TFloatAnimation *moveInXAxisPlayer1;
	TFloatAnimation *moveInYAxisPlayer1;
	TTimer *groundMovement;
	TTimer *timerForPlayerMovementExecute;
	TCornerButton *CornerButton1;
	TColorAnimation *ColorAnimation1;
	TCornerButton *CornerButton2;
	TFloatAnimation *moveInXAxisPlayer2;
	TFloatAnimation *moveInYAxisPlayer2;
	TImage *field19Port;
	TImage *field20Port;
	TImage *field22Port;
	TImage *field23Port;
	TImage *field01Port;
	TImage *field04Port;
	TImage *field03Port;
	TImage *field06Port;
	TImage *field14Port;
	TImage *field15Port;
	TImage *field12Port;
	TImage *field10Port;
	TImage *field28Port;
	TImage *field29Port;
	TImage *field33Port;
	TImage *field34Port;
	TImage *field35Port;
	TImage *field31Port;
	TImage *field25Port;
	TImage *field26Port;
	TFloatAnimation *moveInXAxisPlayer3;
	TFloatAnimation *moveInYAxisPlayer3;
	TFloatAnimation *moveInXAxisPlayer4;
	TFloatAnimation *moveInYAxisPlayer4;
	TImage *background;
	TplayerStatisticsBoxFrame *playerStatisticsBoxFrame2;
	TplayerStatisticsBoxFrame *playerStatisticsBoxFrame1;
	TGlyph *player1;
	TGlyph *player2;
	TGlyph *player3;
	TGlyph *player4;
	TplayerStatisticsBoxFrame *playerStatisticsBoxFrame3;
	TplayerStatisticsBoxFrame *playerStatisticsBoxFrame4;
	TImageList *netherlandsPortImageList;
	TGlyph *field01PortGlyph;
	TImageList *spainPortImageList;
	TImageList *greatBritainPortImageList;
	TImageList *francePortNorthEastImageList;
	TImageList *portugalPortImageList;
	TImageList *francePortSouthEastImageList;
	TGlyph *field03PortGlyph;
	TGlyph *field04PortGlyph;
	TGlyph *field06PortGlyph;
	TGlyph *field10PortGlyph;
	TGlyph *field12PortGlyph;
	TGlyph *field14PortGlyph;
	TGlyph *field15PortGlyph;
	TGlyph *field19PortGlyph;
	TGlyph *field22PortGlyph;
	TGlyph *field23PortGlyph;
	TGlyph *field20PortGlyph;
	TGlyph *field25PortGlyph;
	TGlyph *field26PortGlyph;
	TGlyph *field29PortGlyph;
	TGlyph *field28PortGlyph;
	TGlyph *field31PortGlyph;
	TGlyph *field33PortGlyph;
	TGlyph *field34PortGlyph;
	TGlyph *field35PortGlyph;
	void __fastcall startStopThrowingClick(TObject *Sender);
	void __fastcall timerForDiceTimer(TObject *Sender);
	void __fastcall groundMovementTimer(TObject *Sender);
	void __fastcall timerForPlayerMovementExecuteTimer(TObject *Sender);
	void __fastcall CornerButton1Click(TObject *Sender);
	void __fastcall CornerButton2Click(TObject *Sender);
	void __fastcall playerStatisticsBoxFrame1Click(TObject *Sender);
	/*void __fastcall playerStatisticsBoxFrame1boxImageMouseEnter(TObject *Sender);
	void __fastcall playerStatisticsBoxFrame1boxImageMouseLeave(TObject *Sender);
	void __fastcall playerStatisticsBoxFrame2boxImageMouseEnter(TObject *Sender);
	void __fastcall playerStatisticsBoxFrame2boxImageMouseLeave(TObject *Sender);
	void __fastcall playerStatisticsBoxFrame3boxImageMouseEnter(TObject *Sender);
	void __fastcall playerStatisticsBoxFrame3boxImageMouseLeave(TObject *Sender);
	void __fastcall playerStatisticsBoxFrame4boxImageMouseEnter(TObject *Sender);
	void __fastcall playerStatisticsBoxFrame4boxImageMouseLeave(TObject *Sender); */
private:	// User declarations


public:		// User declarations
	int fieldsCounter;
	int drawnNumber;
	unsigned int iterator;

	int indexOfPlayer;
	vector<bool> playersWhoAreStillInGame;
    int numberOfPlayers;
	vector<Player*> players;
    vector<Field*> fieldsVector;
	__fastcall Tframe1Map(TComponent* Owner);
	//friend void throwDice();
	void fillFieldsVectorWithFields();
};
//---------------------------------------------------------------------------
extern PACKAGE Tframe1Map *frame1Map;
//---------------------------------------------------------------------------
#endif
