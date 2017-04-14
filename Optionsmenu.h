//---------------------------------------------------------------------------

#ifndef OptionsmenuH
#define OptionsmenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include "Mainmenu.h"
//---------------------------------------------------------------------------
class TOptions_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *gra_w_oknie;
	TImage *muzyka;
	TImage *wroc;
	TImage *ustawienia;
	TImage *checkoff_gra_w_oknie;
	TImage *checkoff_muzyka;
	TImage *checkon_gra_w_oknie;
	TImage *checkon_muzyka;
	TImage *volumeBar;
	TImage *volumeButton;
	void __fastcall wrocClick(TObject *Sender);
	void __fastcall checkon_gra_w_oknieClick(TObject *Sender);
	void __fastcall checkoff_gra_w_oknieClick(TObject *Sender);
	void __fastcall checkoff_muzykaClick(TObject *Sender);
	void __fastcall checkon_muzykaClick(TObject *Sender);
	void __fastcall volumeButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TOptions_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptions_frame *Options_frame;
//---------------------------------------------------------------------------
#endif
