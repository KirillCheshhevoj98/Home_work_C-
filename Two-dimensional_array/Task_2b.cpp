#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

int main()
{
	/*
		�)	����� ���� ��������� s-�� ������� �������. 
	*/
	setlocale(LC_ALL, "RUS");

	const int MAXR = 10, MAXC = 15;

	int array[MAXR][MAXC];
	int sizeR, sizeC;
	int sum_s_column = 0;

	printf("Enter the number of rows[1...%d]: ", MAXR);
	scanf("%d", &sizeR);

	while (sizeR < 1 || sizeR>MAXR)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		scanf("%d", &sizeR);
	}

	printf("Enter the number of columns[1...%d]: ", MAXC);
	scanf("%d", &sizeC);

	while (sizeC < 1 || sizeC > MAXC)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		scanf("%d", &sizeC);
	}

	srand(time(0));
	int minRange = -5, maxRange = 5;
	for (int i = 0; i < sizeR; i++)
	{
		for (int j = 0; j < sizeC; j++)
		{
			array[i][j] = rand() % (maxRange - minRange + 1) + minRange;
		}
	}

	printf("The original array\n");

	for (int i = 0; i < sizeR; i++)
	{
		for (int j = 0; j < sizeC; j++)
		{
			printf("%4d ", array[i][j]);
		}
		printf("\n");
	}

	int num;

	printf("Enter number column\n");
	scanf("%d", &num);
	while (num < 1 || num>sizeR)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		scanf("%d", &num);
	}

	for (int i = 0; i < sizeR; i++)
	{
		sum_s_column += array[i][num - 1];
	}

	printf("The sum of all elements of the %d-th column of the array: %d", num, sum_s_column);
	getchar();
	return 0;
}