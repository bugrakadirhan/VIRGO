///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Copyright (c) 2019 Buğra Kadirhan.                                        //
//                                                                           //
// Licensed under the Apache License, Version 2.0 (the "License");           //
// you may not use this file except in compliance with the License.          //
// You may obtain a copy of the License at                                   //
//                                                                           //
//   http://www.apache.org/licenses/LICENSE-2.0                              //
//                                                                           //
// Unless required by applicable law or agreed to in writing, software       //
// distributed under the License is distributed on an "AS IS" BASIS,         //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  //
// See the License for the specific language governing permissions and       //
// limitations under the License.                                            //
//                                                                           //
// VIRGO/windows/main.cpp: Defines VIRGO entry point for Windows OS.         //
//                                                                           //
// NOTE: This file is for 'sketching' purposes, means that you can test your //
//       ideas with help of this code. It will contain a couple of methods   //
//       to help with experimentation. But don't forget to document your     //
//       experiments same as production code! And never commit is as an      //
//       update. You can add this 'note' block to header of your code files  //
//       to declare that they are an experiment, which is not intended to be //
//       committed as a version update.                                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// Pass -DUNICODE to compile for unicode.
//
// Use LPTSTR, TCHAR and TEXT() macro to ensure compatibility with two encoding
// systems without code being changed.

#include <windows.h>

// Define prototype of window procedure.
LRESULT CALLBACK WindowProc(HWND   hWnd,     // - Window handle
                            UINT   uMsg,     // - Message ID
                            WPARAM wParam,   // - 1st parameter
                            LPARAM lParam);  // - 2nd parameter

// Application entry point.
int WINAPI _tWinMain(HINSTANCE hInstance,    // - Instance handle
                     HINSTANCE hPrevInstance,// - Not used in Win32.
                     LPTSTR    lpCmdLine,    // - Command line pointer.
                     int       nCmdShow)     // - Window visibility?
{
    LPTSTR szClassName = TEXT("CVirgoSample");

    WNDCLASSEX wndClass = {};                // 1. Define a window class struct
                                             //
    ZeroMemory(&wndClass, sizeof(wndClass)); // Initialize wndClass to zero.
                                             //
                                             // * Initializing every variable
                                             // to zero prevents some of weird
                                             // bugs from 'bugging' our code...
                                             //
                                             // 2. Fill that structure
                                             //
    wndClass.lpfnWndProc    = &WindowProc;   // -Pointer to window procedure
    wndClass.hInstance      = hInstance  ;   // -Handle to application instance
    wndClass.lpszClassName  = szClassName;   // -Our window's class name.
                                             //
    RegisterClassEx(&wndClass);              // 3. Register the class into
                                             // system's window class registry.
                                             //
                                             // * Maybe I should check for
                                             // RegisterClassEx()'s result as
                                             // well?
                                             //
                                             // 4. Create the window of class
                                             // we've just registered recently.
                                             //
    HWND hWnd = CreateWindowEx (0,                           // - Optional
                                                             // window styles
                                                             //
                                szClassName,                 // - Window class
                                                             //
                                TEXT("VIRGO Sample Window"), // - Window title
                                                             //
                                WS_OVERLAPPEDWINDOW,         // - Window style
                                                             //
                                CW_USEDEFAULT,               // - Size and posi
                                                             // tion.
                                                             //
                                CW_USEDEFAULT,               // "
                                                             //
                                CW_USEDEFAULT,               // "
                                                             //
                                CW_USEDEFAULT,               // "
                                                             //
                                NULL,                        // - Parent window
                                                             //
                                NULL,                        // - Menu
                                                             //
                                hInstance,                   // - Instance hand
                                                             // le.
                                                             //
                                NULL                         // - Additional ap
                                                             // plication data
                                                             //
                                                             // * We can use th
                                                             // is field to sto
                                                             // re C++ window c
                                                             // lass instance.
                                ); // HWND hWnd = CreateWindowEx()

    if (hWnd == NULL)                        // 5. Check if window has been cre
    {                                        // ated successfully.
                                             //
        return 1;                            // Shut the program down if it has
    }                                        // been unsuccessful.
                                             //
    ShowWindow(hWnd, nCmdShow);              // Bring it onto display if succee
                                             // ded.
    MSG msg = { };                           //
    BOOL bMsgRet;                            // 6. Start receiving messages sen
                                             // t to our main window.
                                             //
    while ((bMsgRet = GetMessage(&msg,       // - Pointer to message structure 
                                             // to be filled in.
                                 hWnd,       // - The window handle whose mess
                                             // ages we are interested in.
                                 0,          // - Message ID lower bound.
                                 0)          // - Message ID higher bound.
                                             //
                                ) != 0)      // Loop unless exit message has be
                                             // en sent (returns 0 in that situ
                                             // ation).
    {                                        //
        if (bMsgRet == -1)
        {
            // Handle the error here!
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}
