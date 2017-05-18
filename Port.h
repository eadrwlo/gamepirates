//---------------------------------------------------------------------------
#ifndef PortH
#define PortH
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <vector>
#include "player.h"
using namespace std;

class Player;
class Field
{
	protected:
	int fieldNumber;
	TImage *fieldImagePtr;
	TFrame *cardFramePtr;

	public:
	Field(int fieldNumber, TImage *fieldImagePtr);
	Field(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr);
	int getFieldNumber();
	virtual void mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector);
};

class Port: public Field
{
	//friend class TgreatBritainFrame;
	protected:
	UnicodeString name;
	int conquerCost;
	int visitingPayment;
	int extensionLvl;
	int defensivePower;
	Player *owner;
    Player *currentPlayerLocatedOnField;
	TImage *portImagePtr;

	public:
	Port(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr):Field(fieldNumber, fieldImagePtr, cardFramePtr){};
	void setName();
	UnicodeString getName();
	void mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector);
};

class Whirlpool: public Field
{
	protected:
	UnicodeString name;

	public:
    Whirlpool(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr):Field(fieldNumber, fieldImagePtr, cardFramePtr){}
	void setName();
	void mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector);
	UnicodeString getName();
};

#endif
//---------------------------------------------------------------------------


