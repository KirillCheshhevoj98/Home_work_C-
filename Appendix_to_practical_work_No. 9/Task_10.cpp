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
		Подсчитать количество содержащихся в ней прописных латинских букв.
	*/

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int MAX_SIZE = 10;
	int counter_character = 0;
	char* str = NULL;

	str = (char*)malloc(MAX_SIZE * sizeof(char));

	printf("Enter row:\n");

	fgets(str, MAX_SIZE, stdin);

	trim(str);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			counter_character++;
		}
	}
	str = NULL;

	printf("Count lat character: %d", counter_character);
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