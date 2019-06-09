// sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int num;
	int num2;
	res*p = 0;
	printf("Enter first number:\n>");
	scanf("%d", &num);
	printf("Enter second number:\n>");
	scanf("%d", &num2);
	printf("Started to solve...\n");
	Sum(num, num2, &p);
	printf("Done\n");
	printf("Started to display solution...\n");
	Disp_Sol(num, num2, &p);
	printf("Done\n");
	getch();
}

