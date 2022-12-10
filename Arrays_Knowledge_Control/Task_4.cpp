#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int main()
{
	/*
	Дан массив.
	В массиве найти значение и индекс наибольшего из отрицательных элементов.
	*/

	setlocale(LC_ALL, "rus");
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size, max, imax;
	bool flag;
	printf("Enter the number of elements[1..%d]\n", MAX_SIZE);
	scanf("%d", &size);
	while (size<1 || size>MAX_SIZE)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		scanf("%d", &size);
	}

	srand(time(0));
	int startRange = -10, endRange = 10;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (endRange - startRange + 1) + startRange;
	}

	printf("Source array\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d) %d\n", i + 1, arr[i]);
	}

	int maxNeg, iMaxNeg, fNeg = 0;

	for (int i = 0; i < size && fNeg == 0; i++)
	{
		if (arr[i] < 0)
		{
			iMaxNeg = i;
			maxNeg = arr[i];
			fNeg = 1;
		}
	}

	if (fNeg == 1)
	{
		for (int i = iMaxNeg + 1; i < size; i++)
		{
			if (arr[i] < 0 && arr[i] >= maxNeg)
			{
				iMaxNeg = i;
				maxNeg = arr[i];
			}
		}
		printf("Max negative: %d\n", maxNeg);
		printf("Index: %d\n", iMaxNeg);
	}
	else
	{
		printf("There are no negative numbers");
	}
	getchar();
	return 0;
}
