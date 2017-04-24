//---------------------------------------------------------------------------
#include <iostream>
#include <FMX.Objects.hpp>

using namespace std;
class Player;
class Field
{
	protected:
	int fieldNumber;
	TImage *fieldImagePtr;
	TImage *cardImagePtr;

	public:
	Field(int fieldNumber, TImage *fieldImagePtr);
	Field(int fieldNumber, TImage *fieldImagePtr, TImage *cardImagePtr);
	int getFieldNumber();
	virtual void mainEventWhenPlayerIsOnTheField(Player *player);
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
	void mainEventWhenPlayerIsOnTheField(Player *player);
};

class Whirpool: public Field
{
	protected:
	string name;

	public:
    Whirpool(int fieldNumber, TImage *fieldImagePtr, TImage *cardImagePtr):Field(fieldNumber, fieldImagePtr, cardImagePtr){}
	void setName();
	void mainEventWhenPlayerIsOnTheField(Player *player);
	string getName();
};


//---------------------------------------------------------------------------


