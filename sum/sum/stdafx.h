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

struct res{ int num; int snum=0; res*pnext; };
void Sum(char* num, char* num2, res** p);
res* push(int num, res*phead);
res* pop(res*phead);
int IsEmpty(res*phead);
void Disp_Sol(char* num,char* num2, res* p);



// TODO: reference additional headers your program requires here
