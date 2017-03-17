//---------------------------------------------------------------------------
#include <iostream>
#include <FMX.Objects.hpp>

using namespace std;

struct positionOnMap
{
	int X;
	int Y;
    int fieldNumber;
};

class Player
{
	protected:
	string name;
	positionOnMap currentPositionOnMap;
	int ownedMoney;
	TImage *playerImagePtr;

	public:
	Player();
	void setName(string _name);
	string getName();
    void movePlayer(int fieldNr);

};

class Port
{
	protected:
    string name;
	int portNumber;
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


