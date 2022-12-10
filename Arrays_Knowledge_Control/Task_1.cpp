#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int main()
{
	/*
	¬ массиве произвольных чисел положительные элементы уменьшить в двое, а отрицательные элементы заменить на значени€ их индексов.
	*/

	setlocale(LC_ALL, "rus");
	const int MAX_SIZE = 100;
	double arr[MAX_SIZE];
	int size;

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
		printf("%d) %.1lf\n", i + 1, arr[i]);
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			arr[i] = (double)arr[i] / 2;
		}
		else
		{
			if (arr[i] == 0)
			{
				arr[i] == 0;
			}
			else
			{
				arr[i] = i + 1;
			}
		}
	}

	printf("Processed array\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d) %.1lf\n", i + 1, arr[i]);
	}
	getchar();
	return 0;
}
