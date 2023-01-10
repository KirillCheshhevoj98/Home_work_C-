#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include <iostream>

int main()
{
	/*
		Дано четное число N (> 0) и символы C1 и C2.
		Вывести строку длины N, которая состоит из чередующихся символов C1 и C2, начиная с C1. 
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char C1,C2;
	int N;
	char* str = NULL;

	printf("Enter character №1: ");
	fflush(stdin);
	scanf("%c", &C1);

	printf("Enter character №2: ");
	fflush(stdin);
	std::cin >> C2;

	printf("Enter string length: ");
	scanf("%d", &N);
	while (N < 0)
	{
		printf("Error lenght\n");
		printf("Enter string length: ");
		fflush(stdin);
		scanf("%d", &N);
	}
	str = (char*)malloc(N * sizeof(char));

	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			str[i] = C1;
		}
		else
		{
			str[i] = C2;
		}
		
		printf("%c", str[i]);
	}

	str = (char*)realloc(str, (strlen(str) + 1) * sizeof(char));
	str = NULL;

	getchar();
	return 0;
}