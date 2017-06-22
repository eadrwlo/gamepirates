//---------------------------------------------------------------------------

#ifndef playerStatisticsBoxH
#define playerStatisticsBoxH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Ani.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class TplayerStatisticsBoxFrame : public TFrame
{
__published:	// IDE-managed Components
	TImage *boxImage;
	TLabel *nameLabel;
	TLabel *moneyLabel;
	TLabel *shipLvlLabel;
	TLabel *strengthLabel;
	TLabel *percentLabel;
	TImage *redFrame;
	TImageList *playerIconList;
	TGlyph *playerIcon;
private:	// User declarations
public:		// User declarations
	__fastcall TplayerStatisticsBoxFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TplayerStatisticsBoxFrame *playerStatisticsBoxFrame;
//---------------------------------------------------------------------------
#endif
