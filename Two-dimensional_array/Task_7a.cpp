#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

int main()
{
	/*
		a) Cтроку с максимальной суммой элементов.
		Если таких строк несколько, должен быть найден номер самой нижней из них; 
	*/
	setlocale(LC_ALL, "RUS");

	const int MAXR = 10, MAXC = 15;

	int array[MAXR][MAXC];
	int sizeR, sizeC;
	int sum_elements_of_row = 0;
	int max_sum_elements_of_row = 0;
	int index_row;

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

	for (int i = 0; i < sizeR; i++)
	{
		sum_elements_of_row = 0;
		for (int j = 0; j < sizeC; j++)
		{
			sum_elements_of_row += array[i][j];
		}

		if (sum_elements_of_row >= max_sum_elements_of_row)
		{
			max_sum_elements_of_row = sum_elements_of_row;
			index_row = i;
		}
		printf("The sum of the elements of the %dst row: %d\n", i + 1, sum_elements_of_row);
	}

	printf("A row with the maximum sum of elements:\nindex = %d\nSum = %d", index_row + 1, max_sum_elements_of_row);
	getchar();
	return 0;
}