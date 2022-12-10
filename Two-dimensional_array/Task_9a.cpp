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
			а) которая переставляет две любые строки массива;
	*/
	setlocale(LC_ALL, "RUS");

	const int MAXR = 10, MAXC = 15;

	int array[MAXR][MAXC];
	int sizeR, sizeC;
	int number_row1, number_row2, tmp;

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

	printf("Enter the number of rows №1[1...%d]: ", MAXR);
	scanf("%d", &number_row1);

	while (number_row1 < 0 || number_row1>MAXR)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		printf("Enter the number of row №1[1...%d]: ", MAXR);
		scanf("%d", &number_row1);
	}

	printf("Enter the number of row №2[1...%d]: ", MAXR);
	scanf("%d", &number_row2);

	while (number_row1 < 0 || number_row1>MAXR || number_row1 == number_row2)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		printf("Enter the number of row №2[1...%d]: ", MAXR);
		scanf("%d", &number_row2);
	}

	for (int i = 0; i < sizeR; i++)
	{
		for (int j = 0; j < sizeC; j++)
		{
			tmp = array[number_row1][j];
			array[number_row1][j] = array[number_row2][j];
			array[number_row2][j] = tmp;
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