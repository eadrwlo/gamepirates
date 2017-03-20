//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Optionsmenu.cpp", Options_frame); /* TFrame: File Type */
USEFORM("Unit1.cpp", Form1);
USEFORM("Mainmenu.cpp", Mainmenu_frame); /* TFrame: File Type */
USEFORM("frameMap.cpp", frame1Map); /* TFrame: File Type */
USEFORM("Ingamemenu.cpp", Ingamemenu_frame); /* TFrame: File Type */
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm1), &Form1);
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
