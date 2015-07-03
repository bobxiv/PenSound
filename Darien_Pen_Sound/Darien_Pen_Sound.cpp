// Darien_Pen_Sound.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Darien_Pen_Sound.h"


// Global Variables:
HINSTANCE hInst;								// current instance

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{

	std::ifstream input = std::ifstream("Autorun.inf",std::ios::in);
	if( !input.is_open() )
		return 0;
	std::string str;

	int pos=0;
	std::string tag;
		do
		{
		std::getline(input,str,'\n');
		pos = str.find("=",NULL);
		tag = str.substr(0,pos);
		while( tag.at(0) == ' ' )
			tag.erase(0,1);
		while( tag.at(tag.length()-1) == ' ' )
			tag.erase(tag.length()-1,tag.length());
		}while( tag != "Sound" );

	input.close();

	std::string& WAVname = str;
	pos = str.find("=",NULL);
	WAVname = str.substr(++pos,std::string::npos);
	
	while( WAVname.at(0) == ' ' )
		{
		WAVname.erase(0,1);
		}
	while( WAVname.at(WAVname.length()-1) == ' ' )
		{
		WAVname.erase(WAVname.length()-1,WAVname.length());
		}
	
	PlaySound(WAVname.c_str(),NULL,SND_FILENAME | SND_NODEFAULT);


	return 0;
}




