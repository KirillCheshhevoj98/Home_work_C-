#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>

int main()
{
	/*
		Дан символ C. Вывести два символа, первый из которых предшествует символу C в кодовой таблице, а второй следует за символом C.
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char C;
	int code_char_C, previous_code_char_C, next_code_char_C;
	printf("Enter character: ");
	scanf("%c", &C);

	code_char_C = C;
	previous_code_char_C = code_char_C - 1;
	next_code_char_C = code_char_C + 1;

	printf("Code character %c: %d\n", C, code_char_C);
	printf("Code previous character %c: %d\n", previous_code_char_C, previous_code_char_C);
	printf("Code next character %c: %d\n", next_code_char_C, next_code_char_C);

	getchar();
	return 0;
}