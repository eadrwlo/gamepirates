//---------------------------------------------------------------------------

#ifndef gameLibH
#define gameLibH
#include <iostream>
#include <FMX.Objects.hpp>

using namespace std;
class Player
{
	protected:
	string name;
    int currentPositionOnMap;
	TImage *playerImagePtr;

	public:
	Player();
	void setName();
	string getName();

};


//---------------------------------------------------------------------------
#endif
