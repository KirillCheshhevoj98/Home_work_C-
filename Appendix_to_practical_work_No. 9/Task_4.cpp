#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>

int main()
{
	/*
		Дана непустая строка. Вывести коды ее первого и последнего символа. 
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int MAX_NAME_SIZE = 16;
	char row[MAX_NAME_SIZE];
	int code_first_char, code_last_char;

	printf("Enter row: \n");

	fgets(row, MAX_NAME_SIZE, stdin);

	if (row[strlen(row) - 1] == '\n')
	{
		row[strlen(row) - 1] = '\0';
	}

	code_first_char = row[0];
	code_last_char = row[strlen(row) - 1];

	printf("Row: %s", row);
	printf("Code is first character: %d\n", code_first_char);
	printf("Code is last character: %d\n", code_last_char);

	getchar();
	return 0;
}