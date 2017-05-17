//---------------------------------------------------------------------------

#ifndef playerMenuH
#define playerMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include "frameMap.h"
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class Tplayer_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *backgorund;
	TImageList *playerPictruesList;
	TGlyph *playerAvatar;
	TImage *next_button;
	TImage *previous_button;
	TEdit *nameField;
	void __fastcall next_buttonClick(TObject *Sender);
	void __fastcall previous_buttonClick(TObject *Sender);
	void __fastcall Text1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tplayer_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tplayer_frame *player_frame;
//---------------------------------------------------------------------------
#endif

