// mainmenu.cpp : Defines the entry point for the console application.
//
//#include "div.h"
#include "sum.h"
#include <stdlib.h>
#include <iostream>
int main()
{
	char choice;
	int num=0;
	int num2=0;
	int chk=0;
	while (true){
		system("cls");
		printf("Choose operation for numbers(+,/) or 'e' for exit\n>");
		fflush(stdin);
		std::cin >> choice;
		if (choice == 'e'){
			exit(0);
		}
		putchar (choice);
		printf("Enter first number:\n>");
		scanf("%d", &num);
		printf("Enter second number:\n>");
		scanf("%d", &num2);
		if ((num != 0) && (num2 != 0)){
			if (choice == '+'){
				if (num < num2){
					Sum(num2, num);
				}
				else{
					Sum(num, num2);
				}
			}
			if (choice == '/'){
				//Div(num, num2);
			}
		}
		else{
			printf("Input all numbers and try again\n");
		}
		getchar();
	}
}

