#include "stdafx.h"
#include <stdio.h>

int TenPow(int n){
	int ten = 1;
	for (int i = 1; i <= n; i += 1){
		ten *= 10;
	}
	return ten;
}
int lenInt(int n){
	if (n == 0){
		return 1;
	}
	int l = 0;
	int t = n;
	while (t / TenPow(l - 1) > 0){
		l += 1;
	}
	return l - 1;
}
void MakeSpace(int n){
	if (n < 0){
		return;
	}
	for (int i = 1; i <= n; i++){
		printf(" ");
	}
}
void SplitToArr(int num, int*out){
	int l = lenInt(num);
	int temp = num;
	for (int i = l; i > 0; i--){
		*(out + i) = temp % 10;
		temp /= 10;
	}
}
