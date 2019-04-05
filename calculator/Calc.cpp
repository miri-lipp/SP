#include "Calc.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	double sum1 = 0, sum2 = 0;
	bool minus = false;
	calculator c;
	std::string number1, number2;
	switch (msg) {
	case WM_CREATE:
	{
		HWND button7 = CreateWindow("button", "7", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 150, 100, 50, hWnd, (HMENU)7, nullptr, nullptr);
		HWND button4 = CreateWindow("button", "4", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 200, 100, 50, hWnd, (HMENU)4, nullptr, nullptr);
		HWND button1 = CreateWindow("button", "1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 250, 100, 50, hWnd, (HMENU)1, nullptr, nullptr);
		HWND button2 = CreateWindow("button", "2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 250, 100, 50, hWnd, (HMENU)2, nullptr, nullptr);
		HWND button5 = CreateWindow("button", "5", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 200, 100, 50, hWnd, (HMENU)5, nullptr, nullptr);
		HWND button8 = CreateWindow("button", "8", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 150, 100, 50, hWnd, (HMENU)8, nullptr, nullptr);
		HWND button3 = CreateWindow("button", "3", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 250, 100, 50, hWnd, (HMENU)3, nullptr, nullptr);
		HWND button6 = CreateWindow("button", "6", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 200, 100, 50, hWnd, (HMENU)6, nullptr, nullptr);
		HWND button9 = CreateWindow("button", "9", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 150, 100, 50, hWnd, (HMENU)9, nullptr, nullptr);
		HWND button0 = CreateWindow("button", "0", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			00, 300, 200, 50, hWnd, (HMENU)0, nullptr, nullptr);
		HWND point = CreateWindow("button", ".", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 300, 100, 50, hWnd, (HMENU)11, nullptr, nullptr);
		HWND equation = CreateWindow("button", "=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 300, 100, 50, hWnd, (HMENU)12, nullptr, nullptr);
		HWND addiction = CreateWindow("button", "+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 250, 100, 50, hWnd, (HMENU)13, nullptr, nullptr);
		HWND substraction = CreateWindow("button", "-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 200, 100, 50, hWnd, (HMENU)14, nullptr, nullptr);
		HWND multiplication = CreateWindow("button", "*", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 150, 100, 50, hWnd, (HMENU)15, nullptr, nullptr);
		HWND division = CreateWindow("button", "/", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 100, 100, 50, hWnd, (HMENU)16, nullptr, nullptr);
		HWND perc = CreateWindow("button", "%", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 100, 100, 50, hWnd, (HMENU)17, nullptr, nullptr);
		HWND change = CreateWindow("button", "+/-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 100, 100, 50, hWnd, (HMENU)18, nullptr, nullptr);
		HWND erase = CreateWindow("button", "C", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 100, 100, 50, hWnd, (HMENU)19, nullptr, nullptr);
		HWND buttonbin = CreateWindow("button", "bin", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 100, 100, 50, hWnd, (HMENU)20, nullptr, nullptr);
		HWND bitOr = CreateWindow("button", "OR", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 150, 100, 50, hWnd, (HMENU)21, nullptr, nullptr);
		HWND bitAnd = CreateWindow("button", "AND", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 200, 100, 50, hWnd, (HMENU)22, nullptr, nullptr);
		HWND bitxor = CreateWindow("button", "XOR", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 250, 100, 50, hWnd, (HMENU)23, nullptr, nullptr);
		HWND bitnot = CreateWindow("button", "NOT", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 300, 100, 50, hWnd, (HMENU)24, nullptr, nullptr);
		HWND shiftleft = CreateWindow("button", ">>", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 300, 100, 50, hWnd, (HMENU)25, nullptr, nullptr);
		HWND shiftright= CreateWindow("button", "<<", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 250, 100, 50, hWnd, (HMENU)26, nullptr, nullptr);
		HWND factorial = CreateWindow("button", "!", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 200, 100, 50, hWnd, (HMENU)27, nullptr, nullptr);
		HWND cos = CreateWindow("button", "oct", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 150, 100, 50, hWnd, (HMENU)28, nullptr, nullptr);
		HWND sin = CreateWindow("button", "hex", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 100, 100, 50, hWnd, (HMENU)29, nullptr, nullptr);
		hWnda = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("STATIC"), buf1, WS_CHILD | WS_VISIBLE | SS_RIGHT, 0, 37, 600, 65, hWnd, HMENU(nullptr), GetModuleHandle(nullptr), nullptr);
		hWnda1 = CreateWindowEx(0, TEXT("EDIT"), nullptr, WS_CHILD | WS_VISIBLE | SS_RIGHT, 40, 0, 560, 37, hWnd, (HMENU) ID_EDITCHILD, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), nullptr);
		//boling = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("STATIC"), num, WS_CHILD | WS_VISIBLE | SS_RIGHT, 0, 388, 400, 20, hWnd, HMENU(nullptr), GetModuleHandle(nullptr), nullptr);
		hFont = CreateFontA(50, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
		hFont1 = CreateFontA(30, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
		SendMessage(hWnda, WM_SETFONT, WPARAM(hFont), TRUE);
		SendMessage(hWnda1, WM_SETFONT, WPARAM(hFont1), TRUE);
		ShowWindow(hWnda, 255);

		return 0;
	}
	case WM_DESTROY: 
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case 0: {
			buf1 = "0";
			break;
		}
		case 1: {
			buf1 = "1";
			break;
		}
		case 2: {
			buf1 = "2";
			break;
		}
		case 3: {
			buf1 = "3";
			break;
		}
		case 4: {
			buf1 = "4";
			break;
		}
		case 5: {
			buf1 = "5";
			break;
		}
		case 6: {
			buf1 = "6";
			break;
		}
		case 7: {
			buf1 = "7";
			break;
		}
		case 8: {
			buf1 = "8";
			break;
		}
		case 9: {
			buf1 = "9";
			break;
		}
		case 11: {
			buf1 = ".";
			point = true;
			break;
		}
		case 12:
		{
			buffer2 = buff2;
			if (sign) {
				if (integer)
				{
					if (point)
					{
						MessageBox(hWnda, "Cannot be double", "Error", MB_OK);
					}
					sum1 = atoi(buffer1.c_str());
					sum2 = atoi(buffer2.c_str());
				}
				else
				{
					sum1 = atof(buffer1.c_str());
					sum2 = atof(buffer2.c_str());
				}
				if (add)
					c.Add(sum1, sum2);
				if (sub)
					c.Sub(sum1, sum2);
				if (mul)
					c.Mul(sum1, sum2);
				if (divis)
					c.Div(sum1, sum2);
				if (xxor)
					c.BitXor(sum1, sum2);
				if (orr)
					c.BitOr(sum1, sum2);
				if (annd)
					c.BitAnd(sum1, sum2);
				if (shiftl)
					c.ShiftLeft(sum1, sum2);
				if (shiftr)
					c.ShiftRight(sum1, sum2);
			}
			strcpy_s(buff2, "\0");
			buf1 = "\0";
			str = buff;
			strcpy_s(buff, "\0");
			SetWindowTextA(hWnda1, str.c_str());
			integer = false;
			point = false;
			sign = false;
			sign1 = false;
			break;
		}
		case 13: {
			sign = true;
			add = true;
			break;
		}
		case 14: {
			sign = true;
			sub = true;
			break;
		}
		case 15: {
			sign = true;
			mul = true;
			break;
		}
		case 16: {
			sign = true;
			divis = true;
			break;
		}
		case 17: {
			sign1 = true;
			proc = true;
			break;
		}
		case 18: {
			minus = true;
			//buf1 = "-";
			break;
		}
		case 19:{
			buf1 = "\0";
			strcpy_s(buff1, "");
			strcpy_s(buff2, "\0");
			SetWindowTextA(hWnda1, "");
			break;
		}
		case 20:{
			integer = true;
			bin = true;
			sign1 = true;
			break;
			}
		case 21:{
			integer = true;
			orr = true;
			sign = true;
			break;
		}
		case 22:{
			integer = true;
			annd = true;
			sign = true;
		}
		case 23:{
			integer = true;
			xxor = true;
			sign = true;
			break;
		}
		case 24:{
			integer = true;
			nott = true;
			sign1 = true;
			break;
		}
		case 25:{
			integer = true;
			sign = true;
			shiftl = true;
			break;
		}
		case 26:{
			integer = true;
			sign = true;
			shiftr = true;
			break;
		}
		case 27:{
			integer = true;
			sign1 = true;
			fact = true;
			break;
		}
		case 28:{
			sign1 = true;
			octa = true;
			break;
			}
		case 29:{
			sign1 = true;
			hexa = true;
			break;
			}
		}
		if(!sign && !sign1)
		{
				strcat_s(buff1, sizeof(buff1), buf1);
				SetWindowText(hWnda, buff1);
				buf1 = "\0";
				buffer1 = buff1;
		}
		if (sign) {
			strcpy_s(buff1, "\0");
			strcat_s(buff2, sizeof(buff2), buf1);
			SetWindowText(hWnda, buff2);
		}
		if (sign1)
		{
			strcpy_s(buff1, "\0");
			if (integer)
			{
				if (point)
				{
					MessageBox(hWnda, "Cannot be double", "Error", MB_OK);
				}
				sum1 = atoi(buffer1.c_str());
			}
			else
			{
				sum1 = atof(buffer1.c_str());
			}
			if (hexa)
				c.Hexa(sum1);
			if (octa)
				c.Octa(sum1);
			if (fact)
				c.Factorial(sum1);
			if (proc)
				c.Proc(sum1);
			if (bin)
				c.BitBin(sum1);
			if (nott)
				c.BinNot(sum1);
		}
		return 0;
	}
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}
int WINAPI WinMain(HINSTANCE hInst,	
	HINSTANCE hPrev,		
	LPSTR szCmdLine,	
	int nShowCmd)			
{
	WNDCLASSEX wcx = { 0 };
	wcx.cbSize = sizeof(WNDCLASSEX); 
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WndProc;
	wcx.hInstance = hInst;	
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
	wcx.lpszClassName = "Calculator";
	if (!RegisterClassEx(&wcx))
		return 1;
	HWND hWnd = CreateWindowEx(0,
		"Calculator",
		"Calculator",
		WS_OVERLAPPEDWINDOW | WS_OVERLAPPED|WS_SYSMENU|WS_BORDER,
		CW_USEDEFAULT, 0,
		CW_USEDEFAULT, 0,
		nullptr, 
		nullptr,
		hInst,
		nullptr);
	SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 615 /*width*/, 388 /*height*/, SWP_NOMOVE);
		if (!hWnd)   
			return 2;
		ShowWindow(hWnd, nShowCmd);
		UpdateWindow(hWnd);
	//HWND hWndChild = CreateWindowEx(0, "ChildWClass", (LPCTSTR)nullptr, WS_CHILD | WS_BORDER,
	//		0, 0, 0, 0, hWnd, (HMENU)100, hInst, nullptr);
	//SetWindowPos(hWndChild, HWND_BOTTOM, 0, 0, 315 /*width*/, 288 /*height*/, SWP_NOMOVE);
	//if (!hWndChild)
	//	return 2;
	//ShowWindow(hWndChild, nShowCmd);
	//UpdateWindow(hWndChild);
	MSG msg = { nullptr };
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

