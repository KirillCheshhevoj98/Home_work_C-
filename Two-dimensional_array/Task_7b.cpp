#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

int main()
{
	/*
		b) Cтолбец с минимальной суммой элементов.
		Если таких столбцов несколько, должен быть найден номер самого левого из них
	*/
	setlocale(LC_ALL, "RUS");

	const int MAXR = 10, MAXC = 15;

	int array[MAXR][MAXC];
	int sizeR, sizeC;
	int sum_elements_of_column = 0;
	int min_sum_elements_of_column = 0;
	int index_column;

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

	for (int j = 0; j < sizeC; j++)
	{
		sum_elements_of_column = 0;
		for (int i = 0; i < sizeR; i++)
		{
			sum_elements_of_column += array[i][j];
		}

		if (sum_elements_of_column >= min_sum_elements_of_column)
		{
			min_sum_elements_of_column = sum_elements_of_column;
			index_column = j;
		}
		printf("The sum of the elements of the %dst column: %d\n", j + 1, sum_elements_of_column);
	}

	printf("A column with the minimum sum of elements:\nindex = %d\nSum = %d", index_column + 1, min_sum_elements_of_column);
	getchar();
	return 0;
}