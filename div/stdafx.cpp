

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


void dispSol(int num, int num2, int*res, int o){
	int i = 1;
	printf("%d|%d\n", num, num2);
	printf("%d", *(res + i));
	for (int p = 0; p < (lenInt(num) - lenInt(*(res + i))); p++){
		printf(" ");
	}
	printf(" %d\n", *res);
	while (i != o){
		for (int p = 0; p < (lenInt(*(res + i))); p++){
			printf(" ");
		}
		i++;
		if (*(res + i) == 0){
			i++;
		}
		printf("%d\n", *(res + i));
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
void Div(int num, int num2){
	int first[10];
	int l = lenInt(num);
	SplitToArr(num, first);
	int temp = first[1];
	int second;
	int pos = 1;
	while (temp<num2){
		pos++;
		temp = temp * 10 + first[pos];
	}
	pos++;
	first[0] = temp / num2;
	second = num2*first[0];
	second = temp - second;
	temp = ((second) * 10) + first[pos];
	while (pos <= l){
		while (temp<num2){
			if (pos != l){
				pos++;
				temp = temp * 10 + first[pos];
				first[0] *= 10;
			}
			else{
				second = temp;
				pos = 0;
				break;
			}
		}
		first[0] *= 10;
		if (pos == 0){
			break;
		}
		first[0] += temp / num2;
		second = num2*(first[0]%10);
		pos++;
		if (pos <=l){
			temp = ((temp - second) * 10) + first[pos];
		}
		else{
			second = temp - second;
		}
	}
	printf("%d, ost %d\n\n", first[0], second);
}

