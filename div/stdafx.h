// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
int TenPow(int n);
//struct res{ int num; int snum = 0; res*pnext; };
//res* push(int num, res*phead);
//res* pop(res*phead);
//int IsEmpty(res*phead);
int subDiv(int num, int num2, int*left);
int lenInt(int n);
void dispSol(int num, int num2, int*res,int o);
void Div(int num, int num2);
enum purpose{ all, ans };



// TODO: reference additional headers your program requires here
