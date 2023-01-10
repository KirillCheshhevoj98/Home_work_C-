#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>

int main()
{
	/*
		Дан символ C, изображающий цифру или букву (латинскую или русскую).
		Если C изображает цифру, то вывести строку «digit», если латинскую букву — вывести строку «lat», если русскую — вывести строку «rus».
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char C;
	int code_char_C;
	printf("Enter character: ");
	scanf("%c", &C);
	code_char_C = C;

	if (code_char_C >= 'А' && code_char_C <= 'Я' || code_char_C >= 'а' && code_char_C <= 'я')
	{
		printf("This character is rus");
	}
	else
	{
		if (code_char_C >= '0' && code_char_C <= '9')
		{
			printf("This character is digit");
		}
		if (code_char_C >= 'A' && code_char_C <= 'Z' || code_char_C >= 'a' && code_char_C <= 'z')
		{
			printf("This character is lat");
		}
	}

	getchar();
	return 0;
}