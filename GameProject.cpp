//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("optionsMenu.cpp", Options_frame); /* TFrame: File Type */
USEFORM("game.cpp", gameForm);
USEFORM("mainMenu.cpp", Mainmenu_frame); /* TFrame: File Type */
USEFORM("frameMap.cpp", frame1Map); /* TFrame: File Type */
USEFORM("inGameMenu.cpp", Ingamemenu_frame); /* TFrame: File Type */
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TgameForm), &gameForm);
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
