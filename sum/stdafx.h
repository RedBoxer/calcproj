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
void MakeSpace(int n);
void SplitToArr(int num, int*out);
struct res{ int num; int snum = 0; res*pnext; };
void Sum(int num, int num2, res** p);
void Sum2(int num, int num2);
res* push(int num, res*phead);
res* pop(res*phead);
int IsEmpty(res*phead);
void Disp_Sol(int num,int num2,int result, int*p);
int lenInt(int n);
void AutonomSum(int num, int num2);
enum purpose{all, ans};



// TODO: reference additional headers your program requires here
