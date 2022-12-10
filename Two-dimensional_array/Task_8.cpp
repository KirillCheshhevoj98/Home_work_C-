#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

int main()
{
	/*
		¬ зрительном зале n р€дов, в каждом из которых по m мест (кресел). »нформаци€ о проданных билетах хранитс€ в двумерном массиве, номера строк которого соответствуют номерам р€дов, а номера столбцов Ч  номерам мест. ≈сли билет на то или иное место продан, то соответствующий элемент массива имеет значение 1, в противном случае Ч 0. ќпределить: 
			а) на какой р€д продано больше всего билетов; 
			б) на какой р€д продано меньше всего билетов.

	*/
	setlocale(LC_ALL, "RUS");

	const int MAXR = 10, MAXC = 15;

	int array[MAXR][MAXC];
	int sizeR, sizeC;
	int sum_elements_of_row = 0;
	int max_sum_elements_of_row = 0;
	int min_sum_elements_of_row = 10;
	int index_min_row = 0, index_max_row = 0;

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
	int minRange = 0, maxRange = 1;
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

		if (sum_elements_of_row > max_sum_elements_of_row)
		{
			max_sum_elements_of_row = sum_elements_of_row;
			index_max_row = i;
		}
		
		if (sum_elements_of_row < min_sum_elements_of_row)
		{
			min_sum_elements_of_row = sum_elements_of_row;
			index_min_row = i;
		}
	}

	printf("A row with the maximum sum of elements:\nindex = %d\nSum = %d\n", index_max_row + 1, max_sum_elements_of_row);
	printf("A row with the minimum sum of elements:\nindex = %d\nSum = %d\n", index_min_row + 1, min_sum_elements_of_row);
	getchar();
	return 0;
}