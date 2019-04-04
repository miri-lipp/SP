#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <windows.h> 
#include<cmath>
#define ID_EDITCHILD 100
#include<string>
#include <stdlib.h>
HWND hWnda, hWnda1;
HFONT hFont, hFont1;
char buff1[20], buff2[20];
LPCSTR buf1 = "\0";
char buff[128];
std::string buffer1, buffer2, str, str1;
bool bin = false, orr = false, xxor = false, nott = false, annd = false, point = false, shiftl = false, shiftr = false, octa = false;
bool sign = false, sub = false, mul = false, divis = false, add = false, sign1 = false, proc = false, fact = false, integer = false, hexa = false;
class calculator
{
public:
	void Add(double sum1, double sum2) const
	{
		const double eq = sum1 + sum2;
		sprintf_s(buff, "%0.5lf", eq);
		add = false;
	}
	void Sub(double sum1, double sum2) const
	{
		const double eq = sum1 - sum2;
		sprintf_s(buff, "%lf", eq);
		sub = false;
	}
	void Mul(double sum1, double sum2) const
	{
		const double eq = sum1 * sum2;
		sprintf_s(buff, "%lf", eq);
		mul = false;
	}
	void Div(double sum1, double sum2) const
	{
		double eq = 0;
		if (sum2 == 0)
			MessageBox(hWnda, "Cannot divide by zero", "Error", MB_OK);
		else {
			eq = sum1 / sum2;
			sprintf_s(buff, "%lf", eq);
		}
		divis = false;
	}
	void Proc(double sum1) const
	{
		const double eq = sum1 / 100;
		sprintf_s(buff, "%0.5lf", eq);
		proc = false;
	}
	void Octa(int sum1) const
	{
		_itoa_s(sum1, buff, 8);
		octa = false;
	}
	void Hexa(int sum1) const
	{
		_itoa_s(sum1, buff, 16);
		hexa = false;
	}
	void BitOr(int sum1, int sum2) const
	{
		const int eq = sum1 | sum2;
		sprintf_s(buff, "%d", eq);
		orr = false;
	}
	void BitXor(int sum1, int sum2) const
	{
		const int eq = sum1 ^ sum2;
		sprintf_s(buff, "%d", eq);
		xxor = false;
	}
	void BitAnd(int sum1, int sum2) const
	{
		const int eq = sum1 & sum2;
		sprintf_s(buff, "%d", eq);
		annd = false;
	}
	void ShiftRight(int sum1, int sum2) const
	{
		const long eq = sum1 >> sum2;
		sprintf_s(buff, "%ld", eq);
		shiftr = false;
	}
	void ShiftLeft(int sum1, int sum2) const
	{
		const long eq = sum1 << sum2;
		sprintf_s(buff, "%ld", eq);
		shiftl = false;
	}
	void BinNot(int sum1) const
	{
		const int eq = ~sum1;
		sprintf_s(buff, "%d", eq);
		nott = false;
	}
	void BitBin(int sum1) const
	{
		_itoa_s(sum1, buff, 2);
		bin = false;
	}
	void Factorial(int sum1) const
	{
		long long eq = 1;
		if (sum1 == 0)
		{
			sprintf_s(buff, "%ld", eq);
		}
		else if (sum1 > 0)
		{
			while (sum1)
			{
				eq *= sum1;
				sum1--;
			}
			sprintf_s(buff, "%ld", eq);
		}
		fact = false;
	}
};