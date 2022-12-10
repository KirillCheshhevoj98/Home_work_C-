#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

int main()
{
	/*
		в)  оординаты минимального элемента массива.
		≈сли элементов с минимальным значением несколько, то должны быть найдены координаты самого нижнего и самого правого из них; 
	*/
	setlocale(LC_ALL, "RUS");

	const int MAXR = 10, MAXC = 15;

	int array[MAXR][MAXC];
	int sizeR, sizeC;
	int i_Position_Min_Element = 0, j_Position_Min_Element = 0;

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
	int minRange = -10, maxRange = 10;
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

	int min_value = array[0][0];
	int count = 0;

	for (int j = 0; j < sizeC; j++)
	{
		for (int i = 0; i < sizeR; i++)
		{
			if (array[i][j] < min_value)
			{
					min_value = array[i][j];
					i_Position_Min_Element = i;
					j_Position_Min_Element = j;
			}
		}
	}

	printf("Minimum array element: %d\n", min_value);
	printf("Position of min element: i = %d, j = %d", i_Position_Min_Element, j_Position_Min_Element);
	getchar();
	return 0;
}