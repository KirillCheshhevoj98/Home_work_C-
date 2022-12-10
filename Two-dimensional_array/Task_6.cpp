#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

int main()
{
	/*
		ƒан двумерный массив.
		ѕомен€ть местами первый максимальный и последний минимальный элементы массива.
		ѕрин€ть, что массив просматриваетс€ построчно сверху вниз, а в каждой строке Ч слева направо.
	*/
	setlocale(LC_ALL, "RUS");

	const int MAXR = 10, MAXC = 15;

	int array[MAXR][MAXC];
	int sizeR, sizeC;
	int imax = 0, imin = 0, jmax = 0, jmin = 0;

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

	int max_value = array[0][0];
	int min_value = array[0][0];

	for (int i = 0; i < sizeR; i++)
	{
		for (int j = 0; j < sizeC; j++)
		{
			if (array[i][j] > max_value)
			{
				max_value = array[i][j];
				imax = i;
				jmax = j;
			}
			if (array[i][j] < min_value)
			{
				min_value = array[i][j];
				imin = i;
				jmin = j;
			}
		}
	}

	printf("Maximum array element: %d\n", max_value);
	printf("Minimum array element: %d\n", min_value);

	array[imax][jmax] = min_value;
	array[imin][jmin] = max_value;

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