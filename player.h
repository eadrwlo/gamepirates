#ifndef playerH
#define playerH
#include "Port.h"
#include "playerStatisticsBox.h"
class Field;
class Player
{
	protected:
	UnicodeString name;
	int ownedMoney;
	int attackStrength;
	TGlyph *playerImagePtr;
	TFloatAnimation *playerFlowAnimationX;
	TFloatAnimation *playerFlowAnimationY;
	Field *currentFieldPtr;
	int permissionToMoveInCurrentTurn;
	TplayerStatisticsBoxFrame* playerStatisticsBoxFramePtr;

	public:
	Player(UnicodeString _name, int _ownedMoney, TGlyph *_playerImagePtr,
		   TFloatAnimation *_moveInXAxis, TFloatAnimation *_moveInYAxis,
		   Field *_currentFieldPtr, TplayerStatisticsBoxFrame* playerStatisticsBoxFramePtr);
	void setName(UnicodeString _name);
	UnicodeString getName();
	int getOwnedMoney();
	void setOwnedMoney(int money);
	int getAttackStrength();
	void setAttackStrength(int attackStrength);
	void movePlayerToNeighbouringFiedl();
	void movePlayerToSpecificField(int fieldNumber);
	void updateCurrentField(Field *newFieldPtr);
	Field* getCurrentFieldPtr();
	int getPermissionToMove();
	void allowPlayerForMoveInNextTurn();
	void forbidPlayerForMoveInNextTurn();
};

#endif