#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

int main()
{
	/*
		Дан двумерный массив. Составить программу:
			б) которая переставляет два любых столбца массива. 
	*/
	setlocale(LC_ALL, "RUS");

	const int MAXR = 10, MAXC = 15;

	int array[MAXR][MAXC];
	int sizeR, sizeC;
	int number_column1, number_column2, tmp;

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

	printf("Enter the number of column №1[1...%d]: ", MAXR);
	scanf("%d", &number_column1);

	while (number_column1 < 0 || number_column1>MAXR)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		printf("Enter the number of column №1[1...%d]: ", MAXR);
		scanf("%d", &number_column1);
	}

	printf("Enter the number of column №2[1...%d]: ", MAXR);
	scanf("%d", &number_column2);

	while (number_column2 < 0 || number_column2>MAXR || number_column1 == number_column2)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		printf("Enter the number of column №2[1...%d]: ", MAXR);
		scanf("%d", &number_column2);
	}

	for (int i = 0; i < sizeR; i++)
	{
		for (int j = 0; j < sizeC; j++)
		{
			tmp = array[i][number_column1];
			array[i][number_column1] = array[i][number_column2];
			array[i][number_column2] = tmp;
		}
	}

	printf("The changed array\n");

	for (int i = 0; i < sizeR; i++)
	{
		for (int j = 0; j < sizeC; j++)
		{
			printf("%4d ", array[i][j]);
		}
		printf("\n");
	}

	getchar();
	return 0;
}