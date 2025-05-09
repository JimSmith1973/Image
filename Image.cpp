// Image.cpp

#include "Image.h"

// Global variables
Bitmap g_bitmap;

int ShowAboutMessage( HWND hWndParent )
{
	int nResult = 0;

	MSGBOXPARAMS mbp;

	// Clear message box parameter structure
	ZeroMemory( &mbp, sizeof( mbp ) );

	// Initialise message box parameter structure
	mbp.cbSize		= sizeof( MSGBOXPARAMS );
	mbp.hwndOwner	= hWndParent;
	mbp.hInstance	= NULL;
	mbp.lpszText	= ABOUT_MESSAGE_TEXT;
	mbp.lpszCaption	= ABOUT_MESSAGE_CAPTION;
	mbp.dwStyle		= ( MB_OK | MB_USERICON );
	mbp.lpszIcon	= WINDOW_CLASS_CLASS_DEFAULT_ICON_NAME;

	// Show message box
	nResult = MessageBoxIndirect( &mbp );

	return nResult;

} // End of function ShowAboutMessage

LRESULT CALLBACK MainWindowProcedure( HWND hWndMain, UINT uMessage, WPARAM wParam, LPARAM lParam )
{
	LRESULT lr = 0;

	// Select message
	switch( uMessage )
	{
		case WM_CREATE:
		{
			// A create message

			// Break out of switch
			break;

		} // End of a create message
		case WM_SIZE:
		{
			// A size message

			// Invalidate entire window
			InvalidateRect( hWndMain, NULL, TRUE );

			// Break out of switch
			break;

		} // End of a size message
		case WM_ACTIVATE:
		{
			// An activate message

			// Focus on list box window

			// Break out of switch
			break;

		} // End of an activate message
		case WM_GETMINMAXINFO:
		{
			// A get min max info message
			MINMAXINFO FAR *lpMinMaxInfo;

			// Get min max info structure
			lpMinMaxInfo = ( MINMAXINFO FAR * )lParam;

			// Update min max info structure
			lpMinMaxInfo->ptMinTrackSize.x = WINDOW_CLASS_DEFAULT_MINIMUM_WIDTH;
			lpMinMaxInfo->ptMinTrackSize.y = WINDOW_CLASS_DEFAULT_MINIMUM_HEIGHT;

			// Break out of switch
			break;

		} // End of a get min max info message
		case WM_PAINT:
		{
			// A paint message

			// Stretch bitmap onto main window
			g_bitmap.Center( hWndMain );

			// Break out of switch
			break;

		} // End of a paint message
		case WM_DROPFILES:
		{
			// A drop files message
			DroppedFiles droppedFiles;

			// Get dropped files
			if( droppedFiles.Get( wParam ) )
			{
				// Successfully got dropped files

				// Process dropped files

			} // End of successfully got dropped files

			// Break out of switch
			break;

		} // End of a drop files message
		case WM_COMMAND:
		{
			// A command message

			// Select command
			switch( LOWORD( wParam ) )
			{
				case IDM_FILE_EXIT:
				{
					// A file exit command

					// Destroy window
					DestroyWindow( hWndMain );

					// Break out of switch
					break;

				} // End of a file exit command
				case IDM_HELP_ABOUT:
				{
					// A help about command

					// Show about message
					ShowAboutMessage( hWndMain );

					// Break out of switch
					break;

				} // End of a help about command
				default:
				{
					// Default command

					// Call default procedure
					lr = DefWindowProc( hWndMain, uMessage, wParam, lParam );

					// Break out of switch
					break;

				} // End of default command

			}; // End of selection for command

			// Break out of switch
			break;

		} // End of a command message
		case WM_SYSCOMMAND:
		{
			// A system command message

			// Select system command
			switch( LOWORD( wParam ) )
			{
				case IDM_HELP_ABOUT:
				{
					// A help about system command

					// Show about message
					ShowAboutMessage( hWndMain );

					// Break out of switch
					break;

				} // End of a help about system command
				default:
				{
					// Default system command

					// Call default procedure
					lr = DefWindowProc( hWndMain, uMessage, wParam, lParam );

					// Break out of switch
					break;

				} // End of default system command

			}; // End of selection for system command

			// Break out of switch
			break;

		} // End of a system command message
		case WM_NOTIFY:
		{
			// A notify message

			// Call default handler
			lr = DefWindowProc( hWndMain, uMessage, wParam, lParam );

			// Break out of switch
			break;

		} // End of a notify message
		case WM_CONTEXTMENU:
		{
			// A context menu message
			Menu popupMenu;

			// Load popup menu
			popupMenu.Load( MAKEINTRESOURCE( IDR_CONTEXT_MENU ) );

			// Show popup menu
			popupMenu.TrackPopupMenu( 0, lParam, hWndMain );

			// Break out of switch
			break;

		} // End of a context menu message
		case WM_KEYDOWN:
		{
			// A key down message

			// Select key
			switch( wParam )
			{
				case VK_ESCAPE:
				{
					// The escape key has been pressed

					// Destroy main window
					DestroyWindow( hWndMain );

					// Break out of switch
					break;

				} // End of the escape key has been pressed
				default:
				{
					// Another key has been pressed

					// Call default window procedure
					lr = DefWindowProc( hWndMain, uMessage, wParam, lParam );

					// Break out of switch
					break;

				} // End of another key has been pressed

			}; // End of selection for key

			// Break out of switch
			break;

		} // End of key down message
		case WM_CLOSE:
		{
			// A close message

			// Destroy main window
			DestroyWindow( hWndMain );

			// Break out of switch
			break;

		} // End of a close message
		case WM_DESTROY:
		{
			// A destroy message

			// Terminate thread
			PostQuitMessage( 0 );

			// Break out of switch
			break;

		} // End of a destroy message
		default:
		{
			// Default message

			// Call default window procedure
			lr = DefWindowProc( hWndMain, uMessage, wParam, lParam );

			// Break out of switch
			break;

		} // End of default message

	}; // End of selection for message

	return lr;

} // End of function MainWindowProcedure

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow )
{
	Message message;

	WindowClass mainWindowClass;

	// Initialise main window class
	mainWindowClass.Initialise( MAIN_WINDOW_CLASS_NAME, hInstance, MainWindowProcedure, MAIN_WINDOW_MENU, WINDOW_CLASS_CLASS_DEFAULT_ICON, WINDOW_CLASS_CLASS_DEFAULT_SMALL_ICON, MAIN_WINDOW_CLASS_BACKGROUND );

	// Register main window class
	if( mainWindowClass.Register() )
	{
		// Successfully registered main window class
		Window mainWindow;
		int nDesktopWindowWidth;
		int nDesktopWindowHeight;

		// Get desktop window size
		nDesktopWindowWidth		= GetSystemMetrics( SM_CXSCREEN );
		nDesktopWindowHeight	= GetSystemMetrics( SM_CYSCREEN );

		// Create main window
		if( mainWindow.Create( MAIN_WINDOW_CLASS_NAME, NULL, hInstance, MAIN_WINDOW_TEXT, MAIN_WINDOW_MENU, MAIN_WINDOW_EXTENDED_STYLE, MAIN_WINDOW_STYLE, 0, 0, nDesktopWindowWidth, nDesktopWindowHeight ) )
		{
			// Successfully created main window
			Menu systemMenu;
			ArgumentList argumentList;

			// Get system menu
			systemMenu.GetSystem( mainWindow );

			// Add separator item to system menu
			systemMenu.InsertSeparator( MENU_CLASS_SYSTEM_MENU_SEPARATOR_ITEM_POSITION );

			// Add about item to system menu
			systemMenu.InsertItem( MENU_CLASS_SYSTEM_MENU_ABOUT_ITEM_POSITION, IDM_HELP_ABOUT, MENU_CLASS_SYSTEM_MENU_ABOUT_ITEM_TEXT );

			// Get argument list
			if( argumentList.Get() )
			{
				// Successfully got argument list

			} // End of successfully got argument list

			// Load image into bitmap
			if( !( g_bitmap.Load( IMAGE_FILE_NAME ) ) )
			{
				// Unable to load image into bitmap

				// Allocate string memory
				LPTSTR lpszErrorMessage = new char[ STRING_LENGTH + sizeof( char ) ];

				// Format error message
				wsprintf( lpszErrorMessage, BITMAP_CLASS_UNABLE_TO_LOAD_BITMAP_ERROR_MESSAGE_FORMAT_STRING, IMAGE_FILE_NAME );

				// Display error message
				MessageBox( mainWindow, lpszErrorMessage, ERROR_MESSAGE_CAPTION, ( MB_OK | MB_ICONERROR ) );

				// Free string memory
				delete [] lpszErrorMessage;

			} // End of unable to load image into bitmap

			// Show main window
			mainWindow.Show( nCmdShow );

			// Update main window
			mainWindow.Update();

			// Message loop
			while( message.Get() > 0 )
			{
				// Translate message
				message.Translate();

				// Dispatch message
				message.Dispatch();

			}; // End of message loop

		} // End of successfully created main window
		else
		{
			// Unable to create main window

			// Display error message
			MessageBox( NULL, WINDOW_CLASS_UNABLE_TO_CREATE_WINDOW_ERROR_MESSAGE, ERROR_MESSAGE_CAPTION, ( MB_OK | MB_ICONERROR ) );

		} // End of unable to create main window

	} // End of successfully registered main window class
	else
	{
		// Unable to register main window class

		// Display error message
		MessageBox( NULL, WINDOW_CLASS_CLASS_UNABLE_TO_REGISTER_ERROR_MESSAGE, ERROR_MESSAGE_CAPTION, ( MB_OK | MB_ICONERROR ) );

	} // End of unable to register main window class

	return message;

} // End of function WinMain