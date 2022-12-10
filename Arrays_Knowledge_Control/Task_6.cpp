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
	Переписать его положительные элементы во второй массив, а остальные — в третий.
	*/

	setlocale(LC_ALL, "rus");
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE], arr1[MAX_SIZE], arr2[MAX_SIZE];
	int size, max, imax;
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
	int i1 = 0, i2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			arr1[i1] = arr[i];
			i1++;
		}
		else
		{
			arr2[i2] = arr[i];
			i2++;
		}
	}

	printf("Array positive elements:\n");
	for (int i = 0; i < i1; i++)
	{
		printf("%d) %d\n", i + 1, arr1[i]);
	}

	printf("Array negative elements:\n");
	for (int i = 0; i < i2; i++)
	{
		printf("%d) %d\n", i + 1, arr2[i]);
	}
	getchar();
	return 0;
}
