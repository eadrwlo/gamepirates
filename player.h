#ifndef playerH
#define playerH
#include "Port.h"
class Field;
class Player
{
	protected:
	UnicodeString name;
	int ownedMoney;
	TGlyph *playerImagePtr;
	TFloatAnimation *playerFlowAnimationX;
	TFloatAnimation *playerFlowAnimationY;
	Field *currentFieldPtr;
	int permissionToMoveInCurrentTurn;

	public:
	Player(UnicodeString _name, int _ownedMoney, TGlyph *_playerImagePtr,
		   TFloatAnimation *_moveInXAxis, TFloatAnimation *_moveInYAxis,
		   Field *_currentFieldPtr);
	void setName(UnicodeString _name);
	UnicodeString getName();
	int getOwnedMoney();
    void setOwnedMoney(int money);
	void movePlayerToNeighbouringFiedl();
	void movePlayerToSpecificField(int fieldNumber);
	void updateCurrentField(Field *newFieldPtr);
	Field* getCurrentFieldPtr();
	int getPermissionToMove();
	void allowPlayerForMoveInNextTurn();
	void forbidPlayerForMoveInNextTurn();
};

#endif