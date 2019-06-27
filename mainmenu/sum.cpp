#include "sum.h"

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