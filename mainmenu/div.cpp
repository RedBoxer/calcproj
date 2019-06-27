#include "div.h"
#include "stdafx.h"
#include <stdio.h>

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