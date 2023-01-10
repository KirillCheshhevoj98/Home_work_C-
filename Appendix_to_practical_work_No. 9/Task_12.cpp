#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include <iostream>

void trim(char*);

int main()
{
	/*
		ƒана строка. 
		ѕреобразовать в ней все прописные латинские буквы в строчные. 
	*/

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int MAX_SIZE = 10;
	int counter_capital_letters = 0;
	char* str = NULL;

	str = (char*)malloc(MAX_SIZE * sizeof(char));

	printf("Enter row:\n");

	fgets(str, MAX_SIZE, stdin);

	trim(str);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 'z' - 'Z';
		}
	}

	printf("New row: %s", str);

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