// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int num;
	int num2;
	printf("First number: ");
	scanf("%d", &num);
	printf("Second number: ");
	scanf("%d", &num2);
	Div(num, num2);
	getch();
}

