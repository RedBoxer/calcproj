

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

void Div(int num, int num2){
	int l = lenInt(num);
	int res[900];
	res[0] = 0;
	int temp=num/TenPow(l);
	int i=0;
	int o = 1;
	int numch=0;
	while (temp < num2){
		i += 1;
		temp = num / TenPow(l - i);
	}
	res[o] = temp;
	o += 1;
	res[0]=(res[0]*10)+temp/num2;
	res[o] = temp - (num2*(res[0]%10));
	numch = num - (temp*TenPow(i));
	l -= i;
	i = 0;
	temp = numch / TenPow(l-1);
	while ((l - i)>0){
		while (temp < num2){
			i += 1;
			temp = (res[o] * 10) + (numch / TenPow(l - i));
			res[0] *= 10;
		}
		o += 1;
		res[o] = temp;
		o += 1;
		res[0] += temp / num2;
		res[o] = temp - (num2*(res[0] % 10));
	}
	printf("%d, ost %d\n\n", res[0],res[o]);
	dispSol(num, num2, res,o);
}
void dispSol(int num, int num2, int*res,int o){
	int i = 1;
	printf("%d|%d\n", num, num2);
	printf("%d", *(res + i));
	for (int p = 0; p < (lenInt(num) - lenInt(*(res + i))); p++){
		printf(" ");
	}
	printf(" %d\n", *res);
	while (i != o){
		for (int p = 0; p < (lenInt(*(res + i)));p++){
			printf(" ");
		}
		i++;
		if (*(res + i) == 0){
			i++;
		}
		printf("%d\n", *(res + i));
	}
}

