//---------------------------------------------------------------------------

#ifndef whirlpoolCardH
#define whirlpoolCardH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ImgList.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <System.ImageList.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TwhirlpoolCardFrame : public TFrame
{
__published:	// IDE-managed Components
	TImage *whirpoolCard;
	TGlyph *number1;
	TImageList *commonNumbers;
	TGlyph *number2;
private:	// User declarations
public:		// User declarations
	__fastcall TwhirlpoolCardFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TwhirlpoolCardFrame *whirlpoolCardFrame;
//---------------------------------------------------------------------------
#endif
