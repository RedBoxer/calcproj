// stdafx.cpp : source file that includes just the standard includes
// sum.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
void Sum(char*num, char*num2, res** p){
	int l = strlen(num);
	int l2 = strlen(num2);
	int temp = 0;
	int save = 0;
	for (int i = 0; i <= l; i += 1){
		if ((l2 - i) >= 0){
			temp = *(num + ((l-1) - i)) + *(num2 + ((l-1) - i))+save;
			if (temp >= 10){
				save = temp/10;
			}
		}
		else{
			temp = *(num + ((l-1) - i));
		}
		*(p) = push(temp,*(p));
		(*p)->snum = save;
	}
	*(p) = push(save, *(p));
}
res* push(int num, res*phead){
	res*p = (res*)malloc(sizeof(res));
	p->num = num;
	p->pnext = phead;
	return p;
}
res* pop(res*phead){
	res*p = phead->pnext;
	free(phead);
	return p;
}
int IsEmpty(res*phead){
	if (phead){
		return 0;
	}
		return 1;
}
void Disp_Sol(char* num, char* num2, res* p){
	res* temp = p;
	int l = strlen(num);
	int l2 = strlen(num2);
	for (int i = 0; i <= l; i += 1){
		if (temp->snum != 0){
			printf("%d", temp->snum);
		}
		else{
			printf(" ");
		}
	}
	printf("\n");
	printf("%s\n", num);
	for (int i = 0; i <= (l - l2); i += 1){
		printf(" ");
	}
	printf("%s\n", num);
	for (int i = 0; i <= l; i += 1){
		printf("-");
	}
	printf("\n");
	for (int i = 0; i <= l; i += 1){
		if (i == 0){
			if (p->snum = 0){
				printf(" ");
			}
			else{
				printf("%d", p->snum);
			}
			p = pop(p);
		}
		else{
			printf("%d", p->num);
			p = pop(p);
		}
	}
	printf("\n");
}
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
