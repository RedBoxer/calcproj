

#include "stdafx.h"
int TenPow(int n){
	int ten = 1;
	for (int i = 1; i <= n; i += 1){
		ten *= 10;
	}
	return ten;
}
int lenInt(int n){
	int l = 0;
	int t = n;
	while (t / TenPow(l - 1) > 0){
		l += 1;
	}
	return l - 1;
}
int Form_Ans(res**p){
	int n = 0;
	int out = 0;
	while (!IsEmpty(*p)){
		out += (*p)->num*TenPow(n);
		n += 1;
		(*p) = pop(*p);
	}
	return out;
}
void Sum(int num, int num2, res** p){
	int l = lenInt(num);
	int l2 = lenInt(num2);
	int temp = num;
	int save = 0;
	int n = 1;
	res* p1 = 0;
	res* p2 = 0;
	while (l != 0){
		save=temp % 10;
		p1 = push(save, p1);
		temp=temp / 10;
		l = l - 1;
	}
	temp = num2;
	while (l2 != 0){
		save = temp % 10;
		p2 = push(save, p2);
		temp = temp / 10;
		l2 = l2 - 1;
	}
	save = 0;
	while (!IsEmpty(p1)){
		if (!IsEmpty(p2)){
			temp = p1->num + p2->num + save;
		}
		else{
			temp = p1->num + save;
		}
		save = temp / 10;
		temp = temp - (10 * save);
		*p = push(temp, *p);
		(*p)->snum = save;
		p1 = pop(p1);
		p2 = pop(p2);
		printf("3");
	}
	*p = push(save, *p);
}
res* push(int num, res*phead){
		res* pnew = (res*)malloc(sizeof(res));
		res *p = phead;
		while (p && p->pnext)
		{
			p = p->pnext;
		}
		pnew->num = num;
		pnew->pnext = NULL;
		if (p)
			p->pnext = pnew;
		if (phead)
			return phead;
		return pnew;
}
res* pop(res*phead){
	res *p = NULL;
	if (phead)
		p = phead->pnext;
	free(phead);
	return p;
}
int IsEmpty(res*phead){
	if (phead){
		return 0;
	}
		return 1;
}
void Disp_Sol(int num, int num2, res**p){
	res* temp = *p;
	int l = lenInt(num);
	int l2 = lenInt(num2);
	for (int i = 0; i < l; i += 1){
		if (temp->snum != 0){
			printf("%d", 1);
		}
		else{
			printf(" ");
		}
		temp = temp->pnext;
	}
	printf("\n");
	printf("%d\n", num);
	for (int i = 0; i < (l - l2); i += 1){
		printf(" ");
	}
	printf("%d\n", num2);
	for (int i = 0; i < l; i += 1){
		printf("-");
	}
	printf("\n");
	printf("%d\n", Form_Ans(p));
}

void Disp_SolA(int num, int num2, res **p, purpose por){
	res* temp = *p;
	int l = lenInt(num);
	int l2 = lenInt(num2);
	if (por == all){
		printf("\n");
		printf("%d\n", num);
		for (int i = 0; i < (l - l2); i += 1){
			printf(" ");
		}
		printf("%d\n", num2);
		for (int i = 0; i < l; i += 1){
			printf("-");
		}
	}
	printf("\n");
	printf("%d\n", Form_Ans(p));
}
void AutonomSum(int num, int num2, res** p,purpose por){
	//это версия для работы в умножении
	//для работы нужны функции: lenInt-считает количество цифр(длинну) числа int
	//							push,pop,IsEmpty-реализация стека
	//							TenPow-возвращает 10^n
	//							Form_Ans-создаёт ответ из цифр в стеке
	//							Disp_SolA-отображает полное решение(если последний аргумент all) 
	//									  и только результат(если последний аргумент ans)
	int l = lenInt(num);
	int l2 = lenInt(num2);
	int temp = num;
	int save = 0;
	int n = 1;
	res* p1 = 0;
	res* p2 = 0;
	while (l != 0){
		save = temp % 10;
		p1 = push(save, p1);
		temp = temp / 10;
		l = l - 1;
	}
	temp = num2;
	while (l2 != 0){
		save = temp % 10;
		p2 = push(save, p2);
		temp = temp / 10;
		l2 = l2 - 1;
	}
	save = 0;
	while (!IsEmpty(p1)){
		if (!IsEmpty(p2)){
			temp = p1->num + p2->num + save;
		}
		else{
			temp = p1->num + save;
		}
		save = temp / 10;
		temp = temp - (10 * save);
		*p = push(temp, *p);
		p1 = pop(p1);
		p2 = pop(p2);
	}
	if (por == ans){
		Disp_SolA(num, num2, p, ans);
	}
	else{
		Disp_SolA(num, num2, p, all);
	}
}
