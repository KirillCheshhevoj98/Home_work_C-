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
	Найти сумму элементов с четными номерами и отдельно – с нечетными номерами.
	*/

	setlocale(LC_ALL, "rus");
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size, sum_even = 0, sum_add = 0;

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

	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			sum_even += arr[i];
		}
		else
		{
			if (i % 2 == 1)
			{
				sum_add += arr[i];
			}
		}
	}

	printf("Sum even numbers: %d\n", sum_even);
	printf("Sum add numbers: %d\n", sum_add);
	getchar();
	return 0;
}
