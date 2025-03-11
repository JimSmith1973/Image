// Image.h

#pragma once

#include <windows.h>
#include <commctrl.h>

#include "Resource.h"

#include "..\Common\Ascii.h"
#include "..\Common\Common.h"

#include "..\Classes\ArgumentListClass.h"
#include "..\Classes\BitmapClass.h"
#include "..\Classes\DroppedFilesClass.h"
#include "..\Classes\FontClass.h"
#include "..\Classes\MessageClass.h"
#include "..\Classes\MenuClass.h"
#include "..\Classes\WindowClass.h"
#include "..\Classes\WindowClassClass.h"

#define MAIN_WINDOW_CLASS_NAME													"Main Image Window Class"

#define MAIN_WINDOW_CLASS_MENU_NAME												MAKEINTRESOURCE( IDR_MAIN_MENU )

#define MAIN_WINDOW_CLASS_BACKGROUND											( HBRUSH )( COLOR_DESKTOP + 1 )

#define MAIN_WINDOW_EXTENDED_STYLE												WS_EX_TOPMOST
#define MAIN_WINDOW_STYLE														( WS_POPUP | WS_VISIBLE )
#define MAIN_WINDOW_MENU														NULL

#define MAIN_WINDOW_TEXT														"Image"

#define IMAGE_FILE_NAME															"Tram.jpg"

#define ABOUT_MESSAGE_TEXT														"Image\r\n"							\
																				"\r\n"								\
																				"Written by Jim Smith\r\n"			\
																				"\r\n"								\
																				"March 2025"
