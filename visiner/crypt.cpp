#include "stdafx.h"
#include "visiner.h"
#include "visinerDlg.h"
#include "afxdialogex.h"
#include "crypt.h"

std::vector<wchar_t> info;
std::vector<wchar_t> result;
void readfile(CString input_file)
{
	wchar_t buff;
	std::wifstream in(input_file);
	if(!in.is_open())
	{
		AfxMessageBox(L" Error ", MB_OK);
	}
	while (in)
	{
		in.get(buff);
		info.push_back(buff);
	}
}

void encrypt(CString key)
{
	wchar_t *base = (wchar_t*) key.GetString();
	int k = info.size();
	const wchar_t first_alphabet_letter = 'a';
	int *first_letter = new int [k];
	wchar_t* result_letter = new wchar_t [k];
	int second_letter[256];
	int j = 0, h = 0, m = 0;
	const int alphabet_quantity = 26;

	std::vector<wchar_t>::iterator it;
	for (it = info.begin(); it != info.end(); ++it)
	{
		if(*it == ' ')
		{
			first_letter[j] = 27;
		}
		else {
			first_letter[j] = *it - first_alphabet_letter;
		}
		j++;
	}
	for (auto i = 0; i < wcslen(base); i++)
	{
		second_letter[h] = base[i] - first_alphabet_letter;
		h++;
	}
	for (int i = 0; i < k; i++) {
		if(first_letter[i] == 27)
		{
			result_letter[i] = ' ';
		}
		else {
			result_letter[i] = (first_letter[i] + second_letter[i % (wcslen(base))]) % alphabet_quantity + first_alphabet_letter;
		}
		result.push_back(result_letter[i]);
		m++;
	}
}

void writefile(CString output_file)
{
	std::wofstream out(output_file);
	if(!out.is_open())
	{
		AfxMessageBox(L" Error ", MB_OK);
	}
	std::vector<wchar_t>::iterator it;
	for(it = result.begin(); it != result.end(); ++it)
	{
		out << *it;
	}
}

void test(CString input_file, CString output_file)
{
	char* input = (char*)input_file.GetString();
	char* output = (char*)output_file.GetString();
	const char* p1 = strstr(input, ".txt");
	const char* p2 = strstr(output, ".txt");
	if (p1 == nullptr || p2 == nullptr) {
		AfxMessageBox(L" Error ", MB_OK);
	}
}
