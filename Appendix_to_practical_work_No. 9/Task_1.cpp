#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>

int main()
{
	/*
		��� ������ C. ������� ��� ��� (�� ���� ����� � ������� �������).
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char C;

	printf("Enter character: ");
	scanf("%c", &C);


	printf("Code character %c: %d\n", C, C);
	
	getchar();
	return 0;
}