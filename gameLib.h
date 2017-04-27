//---------------------------------------------------------------------------
#include <iostream>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <vector>
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

class Player
{
	protected:
	string name;
	int ownedMoney;
	TImage *playerImagePtr;
	TFloatAnimation *playerFlowAnimationX;
	TFloatAnimation *playerFlowAnimationY;
	Field *currentFieldPtr;

	public:
	Player(string _name, int _ownedMoney, TImage *_playerImagePtr,
		   TFloatAnimation *_moveInXAxis, TFloatAnimation *_moveInYAxis,
		   Field *_currentFieldPtr);
	void setName(string _name);
	string getName();
	void movePlayer(int drawnNumber);
	void movePlayerToSpecificField(int fieldNumber);
	void updateCurrentField(Field *newFieldPtr);
	Field* getCurrentFieldPtr();
};


class Port: public Field
{
	protected:
	string name;
	int conquerCost;
	int visitingPayment;
	int extensionLvl;
	int defensivePower;
	Player *owner;
	TImage *portImagePtr;

	public:
	Port();
	void setName();
	string getName();
	void mainEventWhenPlayerIsOnTheField(Player *player, TFrame *framePtr);
};

class Whirlpool: public Field
{
	protected:
	string name;

	public:
    Whirlpool(int fieldNumber, TImage *fieldImagePtr, TFrame *cardFramePtr):Field(fieldNumber, fieldImagePtr, cardFramePtr){}
	void setName();
	void mainEventWhenPlayerIsOnTheField(Player *player, TLabel *label, vector<Field*> *fieldsVector);
	string getName();
};


//---------------------------------------------------------------------------


