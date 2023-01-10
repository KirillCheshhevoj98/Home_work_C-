#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include <iostream>

void trim(char*);

int main()
{
	/*
		Дана строка. Подсчитать количество содержащихся в ней цифр. 
	*/

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int MAX_SIZE = 10;
	int counter_number = 0;
	char* str = NULL;

	str = (char*)malloc(MAX_SIZE * sizeof(char));

	printf("Enter row:\n");

	fgets(str, MAX_SIZE, stdin);

	trim(str);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			counter_number++;
		}
	}
	str = NULL;

	printf("Count number: %d", counter_number);
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