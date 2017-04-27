//---------------------------------------------------------------------------

#ifndef gameH
#define gameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.ActnList.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Menus.hpp>
#include <FMX.StdCtrls.hpp>
#include <System.Actions.hpp>
#include "frameMap.h"
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <System.Math.Vectors.hpp>
#include <FMX.Media.hpp>
//---------------------------------------------------------------------------
class TgameForm : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);

private:	// User declarations
public:		// User declarations
	__fastcall TgameForm(TComponent* Owner);
    void mainMenuMusic();
	void formSettings();
	void mainMenu();
	void optionsMenu();
	void game();
	void inGameMenu();
    void startgameMenu();
};
//---------------------------------------------------------------------------
extern PACKAGE TgameForm *gameForm;
extern TMediaPlayer *musicPlayer;
//---------------------------------------------------------------------------
#endif
