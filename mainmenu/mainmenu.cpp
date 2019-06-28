// mainmenu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	char choice='1';
	int num=0;
	int num2=0;
	int chk=0;
	while (true){
		system("cls");
		printf("Choose operation for numbers(+,/,-) or 'e' for exit\n>");
		fflush(stdin);
		gets(&choice);
		if (choice == 'e'){
			exit(0);
		}
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
				Div(num, num2);
			}
		}
		if (choice == '-'){
				Sub(num, num2);
			}
	}
		else{
			printf("Input all numbers and try again\n");
		}
		getch();
	}
}

