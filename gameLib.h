//---------------------------------------------------------------------------
#include <iostream>
#include <FMX.Objects.hpp>

using namespace std;

class Field
{
	protected:
	int fieldNumber;
	TImage *fieldImagePtr;

	public:
	Field(int _fieldNumber, TImage *_fieldImagePtr);
	int getFieldNumber();
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
    void movePlayer(int fieldToMove);

};


class Port
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
};


//---------------------------------------------------------------------------


