

#include "stdafx.h"

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



void Div(int num, int num2){
	if (num2 > num){
		printf("Result: %d/%d", num, num2);
		return;
	}
	int first[10];
	int l = lenInt(num);
	SplitToArr(num, first);
	int temp = first[1];
	int second;
	int pos = 1;
	int chk = 0;
	printf("\n%d|%d\n", num, num2);
	while (temp<num2){
		pos++;
		temp = temp * 10 + first[pos];
	}
	pos++;
	first[0] = temp / num2;
	second = num2*first[0];
	MakeSpace(pos - (lenInt(second)+1));
	printf("%d\n", second);
	second = temp - second;
	temp = ((second)* 10) + first[pos];
	while (pos <= l){
		while (temp<num2){
			if (pos != l){
				pos++;
				temp = temp * 10 + first[pos];
				first[0] *= 10;
			}
			else{
				second = temp;
				chk = 1;
				break;
			}
		}
		first[0] *= 10;
		if (chk == 1){
			break;
		}
		MakeSpace(pos - (lenInt(temp)));
		printf("%d\n", temp);
		first[0] += temp / num2;
		second = num2*(first[0] % 10);
		MakeSpace(pos - (lenInt(temp)));
		printf("%d\n", second);
		pos++;
		if (pos <= l){
			temp = ((temp - second) * 10) + first[pos];

		}
		else{
			second = temp - second;
		}
	}
	MakeSpace(l - lenInt(second));
	printf("%d\n", second);
	printf("\n\nResult: %d", first[0]);
	if (second != 0){
		printf("+%d/%d\n", second, num2);
	}
}
void Sum(int num, int num2){
	int ost[10];
	int first[10];
	int second[10];
	int l = lenInt(num);
	int pos = l;
	int result = 0;
	first[0] = 0;
	SplitToArr(num, first);
	for (int i = 1; i <= l; i++){
		ost[i] = 0;
		second[i] = 0;
	}
	SplitToArr(num2, &second[l - lenInt(num2)]);
	while (pos != 0){
		if (first[pos] + second[pos] >= 10){
			ost[pos - 1] = 1;
			result += ((first[pos] + second[pos]) % 10)*TenPow(l - pos);
			first[pos - 1] += 1;
		}
		else{
			result += (first[pos] + second[pos]) * TenPow(l - pos);
		}
		pos--;
	}
	if (first[0] > 0){
		result += TenPow(l)*first[0];
	}
	Disp_Sol(num, num2, result, &ost[1]);
}
void Disp_Sol(int num, int num2, int result, int*p){
	int l = lenInt(num);
	if (lenInt(result) > l){
		MakeSpace(1);
		for (int i = 0; i < l; i += 1){
			if (*(p + i) != 0){
				printf("%d", *(p + i));
			}
			else{
				MakeSpace(1);
			}
		}
		printf("\n");
		MakeSpace(1);
		printf("%d\n", num);
		MakeSpace((l - lenInt(num2)) + 1);
		printf("%d\n", num2);
		for (int i = 0; i < l + 1; i += 1){
			printf("-");
		}
	}
	else{
		for (int i = 0; i < l; i += 1){
			if (*(p + i) != 0){
				printf("%d", *(p + i));
			}
			else{
				MakeSpace(1);
			}
		}
		printf("\n");
		printf("%d\n", num);
		MakeSpace(l - lenInt(num2));
		printf("%d\n", num2);
		for (int i = 0; i < l; i += 1){
			printf("-");
		}
	}
	printf("\n%d\n", result);
}

