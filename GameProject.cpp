//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("playerStatisticsBox.cpp", playerStatisticsBoxFrame); /* TFrame: File Type */
USEFORM("playerMenu.cpp", player_frame); /* TFrame: File Type */
USEFORM("startgameMenu.cpp", startgameMenu_frame); /* TFrame: File Type */
USEFORM("whirlpoolCard.cpp", whirlpoolCardFrame); /* TFrame: File Type */
USEFORM("portsCard.cpp", portsCardFrame); /* TFrame: File Type */
USEFORM("frameMap.cpp", frame1Map); /* TFrame: File Type */
USEFORM("game.cpp", gameForm);
USEFORM("Ingamemenu.cpp", ingameMenu_frame); /* TFrame: File Type */
USEFORM("pirateShipCard.cpp", pirateShipCardFrame); /* TFrame: File Type */
USEFORM("Mainmenu.cpp", mainMenu_frame); /* TFrame: File Type */
USEFORM("Optionsmenu.cpp", optionsMenu_frame); /* TFrame: File Type */
USEFORM("conquerPortMiniGame.cpp", conquerPortMiniGameForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TgameForm), &gameForm);
		Application->CreateForm(__classid(TconquerPortMiniGameForm), &conquerPortMiniGameForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
