#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include <iostream>

void trim(char*);

int main()
{
	/*
		Дана строка. 
		Вывести строку, содержащую те же символы, но расположенные в обратном порядке. 
	*/

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int MAX_SIZE = 0;
	char* str = NULL;

	printf("Enter string length: ");
	scanf("%d", &MAX_SIZE);
	while (MAX_SIZE < 0)
	{
		printf("Error lenght\n");
		printf("Enter string length: ");
		fflush(stdin);
		scanf("%d", &MAX_SIZE);
	}
	str = (char*)malloc(MAX_SIZE * sizeof(char));

	printf("Enter row:\n");

	fgets(str, MAX_SIZE, stdin);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (str[i] != ' ')
		{
			printf("%c", str[i]);
		}
	}
	str = NULL;

	getchar();
	return 0;
}

void trim(char* tmp)
{
	if (tmp[strlen(tmp) - 1] == '\n')
	{
		tmp[strlen(tmp) - 1] = '\0';
	}
}