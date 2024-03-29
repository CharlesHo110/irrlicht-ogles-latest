// This is a Demo of the Irrlicht Engine (c) 2005-2009 by N.Gebhardt.
// This file is not documented.

#include <irrlicht.h>
#ifdef _IRR_WINDOWS_
#include <windows.h>
#endif

#include <stdio.h>

#include "CMainMenu.h"
#include "CDemo.h"

using namespace irr;

#ifdef _MSC_VER

#pragma comment(lib, "Irrlicht.lib")
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char* argv[])
#endif
{
	bool fullscreen = false;
	bool music = true;
	bool shadows = false;
	bool additive = false;
	bool vsync = false;
	bool aa = false;

#ifndef _IRR_WINDOWS_
	video::E_DRIVER_TYPE driverType = video::EDT_OPENGL;
#else
	video::E_DRIVER_TYPE driverType = video::EDT_DIRECT3D9;
#endif

	CMainMenu menu;

//#ifndef _DEBUG
	if (menu.run(fullscreen, music, shadows, additive, vsync, aa, driverType))
//#endif
	{
		CDemo demo(fullscreen, music, shadows, additive, vsync, aa, driverType);
		demo.run();
	}

	return 0;
}

