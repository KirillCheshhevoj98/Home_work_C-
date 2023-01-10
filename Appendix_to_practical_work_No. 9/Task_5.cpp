#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>

int main()
{
	/*
		Дано целое число N (> 0) и символ C. Вывести строку длины N, которая состоит из символов C.
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char C;
	int N;
	char* str = NULL;
	printf("Enter character: ");
	scanf("%c", &C);

	printf("Enter string length: ");
	scanf("%d", &N);

	str = (char*)malloc(N * sizeof(char));
	
	for (int i = 0; i < N; i++)
	{
		str[i] = C;
		printf("%c", str[i]);
	}

	str = (char*)realloc(str, (strlen(str) + 1) * sizeof(char));
	str = NULL;

	getchar();
	return 0;
}