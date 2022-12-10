#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>

int main()
{
	/*
		сумму и количество четных положительных элементов массива.
	*/
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size;

	printf("Enter size array[1...%d]: ", MAX_SIZE);
	scanf("%d", &size);

	while (size < 1 || size > 100)
	{
		printf("Incorrect input\n");
		printf("Enter size array[1...%d]: ", MAX_SIZE);
		fflush(stdin);
		scanf("%d", &size);
	}

	srand(time(0));
	int startRange = -10, endRange = 10;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (endRange - startRange + 1) + startRange;
	}

	printf("Original array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d element = %d\n", i + 1, arr[i]);
	}

	int sum = 0, counter = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0 && arr[i] > 0)
		{
			sum += arr[i];
			counter++;
		}
	}

	printf("Sum elements array = %d\nCounter positive and even number %d", sum, counter);
	getchar();
	return 0;
}
