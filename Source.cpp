#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <windows.h>

TCHAR szClassName[] = TEXT("Window");
HWND hList;
WNDPROC DefaultListWndProc;

LPCTSTR GetKeyName(LONG_PTR keyCode)
{
	static TCHAR szUnknown[256];
	LPTSTR p = 0;
	switch (keyCode)
	{
	case 0x08: p = TEXT("BackSpace"); break;
	case 0x09: p = TEXT("Tab"); break;
	case 0x0D: p = TEXT("Enter"); break;
	case 0x10: p = TEXT("Shift"); break;
	case 0x11: p = TEXT("Ctrl"); break;
	case 0x12: p = TEXT("Alt"); break;
	case 0x13: p = TEXT("Pause"); break;
	case 0x14: p = TEXT("Caps Lock"); break;
	case 0x1B: p = TEXT("ESC"); break;
	case 0x1C: p = TEXT("変換"); break;
	case 0x1D: p = TEXT("無変換"); break;
	case 0x20: p = TEXT("Space"); break;
	case 0x21: p = TEXT("PageUp"); break;
	case 0x22: p = TEXT("PageDown"); break;
	case 0x23: p = TEXT("End"); break;
	case 0x24: p = TEXT("Home"); break;
	case 0x25: p = TEXT("←"); break;
	case 0x26: p = TEXT("↑"); break;
	case 0x27: p = TEXT("→"); break;
	case 0x28: p = TEXT("↓"); break;
	case 0x2B: p = TEXT("+"); break;
	case 0x2C: p = TEXT("Prt Sc"); break;
	case 0x2D: p = TEXT("Insert"); break;
	case 0x2E: p = TEXT("Delete"); break;
	case 0x30: p = TEXT("0"); break;
	case 0x31: p = TEXT("1"); break;
	case 0x32: p = TEXT("2"); break;
	case 0x33: p = TEXT("3"); break;
	case 0x34: p = TEXT("4"); break;
	case 0x35: p = TEXT("5"); break;
	case 0x36: p = TEXT("6"); break;
	case 0x37: p = TEXT("7"); break;
	case 0x38: p = TEXT("8"); break;
	case 0x39: p = TEXT("9"); break;
	case 0x3A: p = TEXT(":"); break;
	case 0x3B: p = TEXT(");"); break;
	case 0x3C: p = TEXT("<"); break;
	case 0x3D: p = TEXT("="); break;
	case 0x3E: p = TEXT(">"); break;
	case 0x3F: p = TEXT("?"); break;
	case 0x40: p = TEXT("@"); break;
	case 0x41: p = TEXT("A"); break;
	case 0x42: p = TEXT("B"); break;
	case 0x43: p = TEXT("C"); break;
	case 0x44: p = TEXT("D"); break;
	case 0x45: p = TEXT("E"); break;
	case 0x46: p = TEXT("F"); break;
	case 0x47: p = TEXT("G"); break;
	case 0x48: p = TEXT("H"); break;
	case 0x49: p = TEXT("I"); break;
	case 0x4A: p = TEXT("J"); break;
	case 0x4B: p = TEXT("K"); break;
	case 0x4C: p = TEXT("L"); break;
	case 0x4D: p = TEXT("M"); break;
	case 0x4E: p = TEXT("N"); break;
	case 0x4F: p = TEXT("O"); break;
	case 0x50: p = TEXT("P"); break;
	case 0x51: p = TEXT("Q"); break;
	case 0x52: p = TEXT("R"); break;
	case 0x53: p = TEXT("S"); break;
	case 0x54: p = TEXT("T"); break;
	case 0x55: p = TEXT("U"); break;
	case 0x56: p = TEXT("V"); break;
	case 0x57: p = TEXT("W"); break;
	case 0x58: p = TEXT("X"); break;
	case 0x59: p = TEXT("Y"); break;
	case 0x5A: p = TEXT("Z"); break;
	case 0x5B: p = TEXT("左Win"); break;
	case 0x5C: p = TEXT("右Win"); break;
	case 0x5D: p = TEXT("Apps"); break;
	case 0x5E: p = TEXT("ハット"); break;
	case 0x60: p = TEXT("テンキー0"); break;
	case 0x61: p = TEXT("テンキー1"); break;
	case 0x62: p = TEXT("テンキー2"); break;
	case 0x63: p = TEXT("テンキー3"); break;
	case 0x64: p = TEXT("テンキー4"); break;
	case 0x65: p = TEXT("テンキー5"); break;
	case 0x66: p = TEXT("テンキー6"); break;
	case 0x67: p = TEXT("テンキー7"); break;
	case 0x68: p = TEXT("テンキー8"); break;
	case 0x69: p = TEXT("テンキー9"); break;
	case 0x6A: p = TEXT("テンキー*"); break;
	case 0x6B: p = TEXT("テンキー+"); break;
	case 0x6D: p = TEXT("テンキー-"); break;
	case 0x6E: p = TEXT("テンキー."); break;
	case 0x6F: p = TEXT("テンキー/"); break;
	case 0x70: p = TEXT("F1"); break;
	case 0x71: p = TEXT("F2"); break;
	case 0x72: p = TEXT("F3"); break;
	case 0x73: p = TEXT("F4"); break;
	case 0x74: p = TEXT("F5"); break;
	case 0x75: p = TEXT("F6"); break;
	case 0x76: p = TEXT("F7"); break;
	case 0x77: p = TEXT("F8"); break;
	case 0x78: p = TEXT("F9"); break;
	case 0x79: p = TEXT("F10"); break;
	case 0x7A: p = TEXT("F11"); break;
	case 0x7B: p = TEXT("F12"); break;
	case 0x7C: p = TEXT("F13"); break;
	case 0x7D: p = TEXT("F14"); break;
	case 0x7E: p = TEXT("F15"); break;
	case 0x7F: p = TEXT("F16"); break;
	case 0x80: p = TEXT("F17"); break;
	case 0x81: p = TEXT("F18"); break;
	case 0x82: p = TEXT("F19"); break;
	case 0x83: p = TEXT("F20"); break;
	case 0x84: p = TEXT("F21"); break;
	case 0x85: p = TEXT("F22"); break;
	case 0x86: p = TEXT("F23"); break;
	case 0x87: p = TEXT("F24"); break;
	case 0x90: p = TEXT("NumLock"); break;
	case 0x91: p = TEXT("ScrollLock"); break;
	case 0xBA: p = TEXT(":"); break;
	case 0xBB: p = TEXT(");"); break;
	case 0xBC: p = TEXT(","); break;
	case 0xBD: p = TEXT("-"); break;
	case 0xBE: p = TEXT("."); break;
	case 0xBF: p = TEXT("/"); break;
	case 0xC0: p = TEXT("@"); break;
	case 0xDB: p = TEXT("["); break;
	case 0xDC: p = TEXT("\\"); break;
	case 0xDD: p = TEXT("]"); break;
	case 0xDE: p = TEXT("^"); break;
	case 0xE2: p = TEXT("\\"); break;
	case 0xF0: p = TEXT("カタカナひらがなローマ字"); break;
	case 0xF2: p = TEXT("カタカナひらがなローマ字"); break;
	case 0xF3: p = TEXT("全角半角"); break;
	case 0xF4: p = TEXT("全角半角"); break;
	default:
		{
			wsprintf(szUnknown, TEXT("不明 0x%x"), keyCode);
			p = szUnknown;
		}
		break;
	}
	return p;
}

LRESULT CALLBACK MyListProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static TCHAR szText[1024];
	switch (msg)
	{
	case WM_CHAR:
		wsprintf(szText, TEXT("WM_CHAR %c"), (TCHAR)wParam);
		SendMessage(hList, LB_ADDSTRING, 0, (LONG_PTR)szText);
		break;
	case WM_KEYDOWN:
		wsprintf(szText, TEXT("WM_KEYDOWN %s"), GetKeyName(wParam));
		SendMessage(hList, LB_ADDSTRING, 0, (LONG_PTR)szText);
		break;
	case WM_KEYUP:
		wsprintf(szText, TEXT("WM_KEYUP %s"), GetKeyName(wParam));
		SendMessage(hList, LB_ADDSTRING, 0, (LONG_PTR)szText);
		break;
	case WM_SYSKEYDOWN:
		wsprintf(szText, TEXT("WM_SYSKEYDOWN %s"), GetKeyName(wParam));
		SendMessage(hList, LB_ADDSTRING, 0, (LONG_PTR)szText);
		break;
	case WM_SYSKEYUP:
		wsprintf(szText, TEXT("WM_SYSKEYUP %s"), GetKeyName(wParam));
		SendMessage(hList, LB_ADDSTRING, 0, (LONG_PTR)szText);
		break;
	default:
		break;
	}
	return CallWindowProc(DefaultListWndProc, hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		hList = CreateWindow(TEXT("LISTBOX"), 0, WS_VISIBLE | WS_CHILD | WS_VSCROLL | LBS_NOINTEGRALHEIGHT, 0, 0, 0, 0, hWnd, (HMENU)IDOK, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		DefaultListWndProc = (WNDPROC)SetWindowLongPtr(hList, GWLP_WNDPROC, (LONG_PTR)MyListProc);
		break;
	case WM_SETFOCUS:
		SetFocus(hList);
		break;
	case WM_SIZE:
		MoveWindow(hList, 0, 0, LOWORD(lParam), HIWORD(lParam), TRUE);
		break;
	case WM_DESTROY:
		SetWindowLongPtr(hList, GWLP_WNDPROC, (LONG_PTR)DefaultListWndProc);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR pCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASS wndclass = {
		CS_HREDRAW | CS_VREDRAW,
		WndProc,
		0,
		0,
		hInstance,
		0,
		LoadCursor(0,IDC_ARROW),
		0,
		0,
		szClassName
	};
	RegisterClass(&wndclass);
	HWND hWnd = CreateWindow(
		szClassName,
		TEXT("キーボードが押されたときのイベントを取得"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		0,
		0,
		hInstance,
		0
	);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
