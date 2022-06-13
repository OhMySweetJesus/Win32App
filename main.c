#include <windows.h>
#include "main.h"

const char g_szClassName[] = "myWindowClass";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpCmdLine, int nCmdShow)
{
  WNDCLASSEX wc;
  HWND hwnd;
  MSG Msg;

  HICON hIcon3;      // icon handle

// Yang icon AND bitmask

  BYTE ANDmaskIcon[] = {0xFF, 0xFF, 0xFF, 0xFF,   // line 1
                        0xFF, 0xFF, 0xC3, 0xFF,   // line 2
                        0xFF, 0xFF, 0x00, 0xFF,   // line 3
                        0xFF, 0xFE, 0x00, 0x7F,   // line 4

                        0xFF, 0xFC, 0x00, 0x1F,   // line 5
                        0xFF, 0xF8, 0x00, 0x0F,   // line 6
                        0xFF, 0xF8, 0x00, 0x0F,   // line 7
                        0xFF, 0xF0, 0x00, 0x07,   // line 8

                        0xFF, 0xF0, 0x00, 0x03,   // line 9
                        0xFF, 0xE0, 0x00, 0x03,   // line 10
                        0xFF, 0xE0, 0x00, 0x01,   // line 11
                        0xFF, 0xE0, 0x00, 0x01,   // line 12

                        0xFF, 0xF0, 0x00, 0x01,   // line 13
                        0xFF, 0xF0, 0x00, 0x00,   // line 14
                        0xFF, 0xF8, 0x00, 0x00,   // line 15
                        0xFF, 0xFC, 0x00, 0x00,   // line 16

                        0xFF, 0xFF, 0x00, 0x00,   // line 17
                        0xFF, 0xFF, 0x80, 0x00,   // line 18
                        0xFF, 0xFF, 0xE0, 0x00,   // line 19
                        0xFF, 0xFF, 0xE0, 0x01,   // line 20

                        0xFF, 0xFF, 0xF0, 0x01,   // line 21
                        0xFF, 0xFF, 0xF0, 0x01,   // line 22
                        0xFF, 0xFF, 0xF0, 0x03,   // line 23
                        0xFF, 0xFF, 0xE0, 0x03,   // line 24

                        0xFF, 0xFF, 0xE0, 0x07,   // line 25
                        0xFF, 0xFF, 0xC0, 0x0F,   // line 26
                        0xFF, 0xFF, 0xC0, 0x0F,   // line 27
                        0xFF, 0xFF, 0x80, 0x1F,   // line 28

                        0xFF, 0xFF, 0x00, 0x7F,   // line 29
                        0xFF, 0xFC, 0x00, 0xFF,   // line 30
                        0xFF, 0xF8, 0x03, 0xFF,   // line 31
                        0xFF, 0xFC, 0x3F, 0xFF};  // line 32

  // Yang icon XOR bitmask

  BYTE XORmaskIcon[] = {0x00, 0x00, 0x00, 0x00,   // line 1
                        0x00, 0x00, 0x00, 0x00,   // line 2
                        0x00, 0x00, 0x00, 0x00,   // line 3
                        0x00, 0x00, 0x00, 0x00,   // line 4

                        0x00, 0x00, 0x00, 0x00,   // line 5
                        0x00, 0x00, 0x00, 0x00,   // line 6
                        0x00, 0x00, 0x00, 0x00,   // line 7
                        0x00, 0x00, 0x38, 0x00,   // line 8

                        0x00, 0x00, 0x7C, 0x00,   // line 9
                        0x00, 0x00, 0x7C, 0x00,   // line 10
                        0x00, 0x00, 0x7C, 0x00,   // line 11
                        0x00, 0x00, 0x38, 0x00,   // line 12

                        0x00, 0x00, 0x00, 0x00,   // line 13
                        0x00, 0x00, 0x00, 0x00,   // line 14
                        0x00, 0x00, 0x00, 0x00,   // line 15
                        0x00, 0x00, 0x00, 0x00,   // line 16

                        0x00, 0x00, 0x00, 0x00,   // line 17
                        0x00, 0x00, 0x00, 0x00,   // line 18
                        0x00, 0x00, 0x00, 0x00,   // line 19
                        0x00, 0x00, 0x00, 0x00,   // line 20

                        0x00, 0x00, 0x00, 0x00,   // line 21
                        0x00, 0x00, 0x00, 0x00,   // line 22
                        0x00, 0x00, 0x00, 0x00,   // line 23
                        0x00, 0x00, 0x00, 0x00,   // line 24

                        0x00, 0x00, 0x00, 0x00,   // line 25
                        0x00, 0x00, 0x00, 0x00,   // line 26
                        0x00, 0x00, 0x00, 0x00,   // line 27
                        0x00, 0x00, 0x00, 0x00,   // line 28

                        0x00, 0x00, 0x00, 0x00,   // line 29
                        0x00, 0x00, 0x00, 0x00,   // line 30
                        0x00, 0x00, 0x00, 0x00,   // line 31
                        0x00, 0x00, 0x00, 0x00};  // line 32

  hIcon3 = CreateIcon(hInstance,    // application instance
               32,              // icon width
               32,              // icon height
               1,               // number of XOR planes
               1,               // number of bits per pixel
               ANDmaskIcon,     // AND bitmask
               XORmaskIcon);    // XOR bitmask

  // Step 1: Register your window class
  wc.cbSize             = sizeof(WNDCLASSEX);
  wc.style              = 0;
  wc.lpfnWndProc        = WndProc;
  wc.cbClsExtra         = 0;
  wc.hInstance          = hInstance;
  wc.hIcon              = hIcon3; //LoadIcon(NULL, hIcon3);
  wc.hCursor            = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground      = (HBRUSH)(COLOR_WINDOW+1);
  wc.lpszMenuName       = NULL;
  wc.lpszClassName      = g_szClassName;
  wc.hIconSm            = hIcon3; //LoadIcon(NULL, IDI_APPLICATION);


  // TODO: if(!RegisterClassEx...
  // http://www.winprog.org/tutorial/simple_window.html
  if(!RegisterClassEx(&wc))
  {
    MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }

  // Step 2. Creating the window.
  hwnd = CreateWindowEx(
                        WS_EX_CLIENTEDGE,
                        g_szClassName,
                        "The title of my window",
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT, 500, 300,
                        NULL, NULL, hInstance, NULL);

  if (hwnd == NULL)
  {
    MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }

  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  // Step 3: The Message Loop
  while(GetMessage(&Msg, NULL, 0, 0) > 0)
  {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }
  return Msg.wParam;
}
