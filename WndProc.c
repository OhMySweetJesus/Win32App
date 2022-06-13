#include <windows.h>
#include "main.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch(msg)
  {
    case WM_LBUTTONDOWN:
      MessageBox(NULL, "Test Successful!", "NOTIFY", MB_OK);
      break;
    case WM_RBUTTONDOWN:
      MessageBox(NULL, "Another Successful Test!", "NOTIFY", MB_OK);
      break;
    case WM_CLOSE:
      DestroyWindow(hwnd);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
}
