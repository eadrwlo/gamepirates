//---------------------------------------------------------------------------
#ifndef PortH
#define PortH
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <vector>
#include "player.h"
#include "portsCard.h"
using namespace std;

class TportsCardFrame;
enum Nations
{
	PORTUGAL = 1,
	NETHERLANDS = 2,
	GREAT_BRITAIN =	3,
	FRANCE = 4,
	SPAIN = 5
};



class Player;
class Field
{
	protected:
	int fieldNumber;
	TImage *fieldImagePtr;

	public:
	TFrame *cardFramePtr;
    Field(){};
	Field(int fieldNumber, TImage *fieldImagePtr);
	Field(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr);
	int getFieldNumber();
	virtual void mainEventWhenPlayerIsOnTheField(Player *playera, TLabel *label, vector<Field*> *fieldsVector);
};

class Port: public Field
{
	protected:
	UnicodeString name;
	int conquerCost;
	int visitingPayment;
	int extensionLvl;
	int defensivePower;
	Player *owner;
	Player *currentPlayerLocatedOnField;
	TGlyph *portImagePtr;
	TImage *moloImagePtr;
	TportsCardFrame *portsCardFramePtr;

	public:
    Port();
	Port(int fieldNumber, TImage *portImage1Ptr, TGlyph *portImage2Ptr, TFrame *cardFramePtr, int conquerCost, int visitingPayment, UnicodeString name, int nation);
	void setName();
	UnicodeString getName();
	int getConquerCost();
	void setVisitingPayment(int visitingPayment);
    int getVisitingPayment();
	void setOwner(Player *owner);
	Player* getOwner();
	void setCurrentPlayerLocatedOnField(Player *player);
	void setPortImagesPtrByIndex(int index);
	TGlyph* getPortImagesPtr();
	Player *getCurrentPlayerLocatedOnField();
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

class LuckyWind: public Field
{
	unsigned int* iterator;
	public:
	LuckyWind(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr, unsigned int *iterator);
	void mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector);
};

class Shallow: public Field
{
	public:
	Shallow(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr):Field(fieldNumber, fieldImagePtr, cardFramePtr){}
	void mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector);
};

class Storm: public Field
{
	public:
	Storm(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr):Field(fieldNumber, fieldImagePtr, cardFramePtr){}
	void mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector);
};

class PirateShip: public Field
{
	public:
	PirateShip(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr):Field(fieldNumber, fieldImagePtr, cardFramePtr){}
	void mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector);
};

#endif
//---------------------------------------------------------------------------


