#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>

int main()
{
	/*
		��� ������ C, ������������ ����� ��� ����� (��������� ��� �������).
		���� C ���������� �����, �� ������� ������ �digit�, ���� ��������� ����� � ������� ������ �lat�, ���� ������� � ������� ������ �rus�.
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char C;
	int code_char_C;
	printf("Enter character: ");
	scanf("%c", &C);
	code_char_C = C;

	if (code_char_C >= '�' && code_char_C <= '�' || code_char_C >= '�' && code_char_C <= '�')
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