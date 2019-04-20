#pragma once
#include <fstream>
#include <cwchar>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <afxwin.h> 


void readfile(CString input_file);
void encrypt(CString key);
void writefile(CString output_file);
void test(CString input_file, CString output_file);